/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:27:18 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/28 18:46:51 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_error()
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	data_init(t_fractal *fractal)
{
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	event_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, 2, 0, key_handler, fractal);
	// mlx_hook(fractal->mlx_window, 4, , mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, 17, 0, close_handler, fractal);
	// mlx_hook(fractal->mlx_window, 6, , julia_track, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		ft_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, 800, 800, fractal->name);
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		ft_error();
	}
	fractal->image.img_ptr = mlx_new_image(fractal->mlx_connection, 800, 800);
	if (NULL == fractal->image.img_ptr)
	{
		mlx_destroy_image(fractal, fractal->image.img_ptr);
		free(fractal->mlx_connection);
		ft_error();
	}
	fractal->image.img_ptr = mlx_get_data_addr(fractal->image.img_ptr, &fractal->image.bpp,
																&fractal->image.line_len, &fractal->image.endian);
	// event_init(fractal);
	data_init(fractal);
}