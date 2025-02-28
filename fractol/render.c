#include "fractol.h"

static void mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
   if (ft_strncmp(fractal->name, "julia", 5) == 0)
   {}
   else
   {
      c->x = z->x;
      c->y = z->y;
   }
}

static void handel_pixel(int x, int y, t_fractal *fractal)
{
   t_complex   z;
   t_complex   c;
   int         i;

   i = 0;
   z.x = (map(x, -2, 2, 0, 800) * fractal->zoom) + fractal->shift_x;
   z.y = (map(y, -2, 2, 0, 800) * fractal->zoom) + fractal->shift_y;
   mandel_vs_julia(&z, &c, fractal);
}

void fractal_render(t_fractal *fractal)
{
   int   x;
   int   y;

   y = 0;
   while (y < 800)
   {
      x = 0;
      while (x < 800)
      {
         handel_pixel(x, y, fractal);
         x++;
      }
      y++;
   }
}
