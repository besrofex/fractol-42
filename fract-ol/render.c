/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:28:34 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/28 22:11:25 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x <  0 || x >= 800 || y < 0 || y >= 800)
		return ;
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(int *)(img->pixels_ptr + offset) = color;
}

static void mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
   if (ft_strncmp(fractal->name, "julia", 5) == 0)
   {
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
   else
   {
      c->x = z->x;
      c->y = z->y;
   }
}

static int handel_pixel(int x, int y, t_fractal *fractal)
{
   t_complex   z;
   t_complex   c;
   int         i;
   int         color;

   i = 0;
   z.x = ((map(x, -2, 2, 0, 800) * fractal->zoom)) + fractal->shift_x;
   z.y = ((map(y, -2, 2, 0, 800) * fractal->zoom)) + fractal->shift_y;
   mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
			return (i * fractal->color);
		i++;
	}
	return (0);
}

void fractal_render(t_fractal *fractal)
{
int   color;
   int   x;
   int   y;

   y = 0;
   while (y < 800)
   {
      x = 0;
      while (x < 800)
      {
         color = handel_pixel(x, y, fractal);
         my_pixel_put(x, y, fractal->image,color);
         x++;
      }
      y++;
   }
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->image.img_ptr, 0, 0);
}
