/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:28:34 by ylabser           #+#    #+#             */
/*   Updated: 2025/06/10 21:12:23 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	map(double value, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (value - old_min)
		/ (old_max - old_min) + new_min);
}

static int	handel_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.x = ((map(x, -2, 2, 0, 800) * fractal->zoom));
	z.y = ((map(y, -2, 2, 0, 800) * fractal->zoom));
	if (ft_strncmp(fractal->name, "julia", 5) == 0)
	{
		c.x = fractal->julia_x;
		c.y = fractal->julia_y;
	}
	else
	{
		c.x = z.x;
		c.y = z.y;
	}
	while (i < fractal->iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
			return (i * fractal->color);
		i++;
	}
	return (0);
}

void	fractal_render(t_fractal *fractal)
{
	int	color;
	int	off;
	int	x;
	int	y;

	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			color = handel_pixel(x, y, fractal);
			off = (y * fractal->image.line_len)
				+ (x * (fractal->image.bpp / 8));
			*(unsigned int *)(fractal->image.pixels_ptr
					+ off) = (unsigned int)color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window, fractal->image.img_ptr, 0, 0);
}
