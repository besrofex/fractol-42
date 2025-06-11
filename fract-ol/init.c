/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:27:18 by ylabser           #+#    #+#             */
/*   Updated: 2025/06/11 16:55:49 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_error(void *ptr)
{
	free(ptr);
	exit(1);
}

static void	event_init(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_window, key_handler, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, 17, 0, close_handler, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		exit(1);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			800, 800, fractal->name);
	if (NULL == fractal->mlx_window)
		ft_error(fractal->mlx_connection);
	fractal->image.img_ptr = mlx_new_image(fractal->mlx_connection, 800, 800);
	if (NULL == fractal->image.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		ft_error(fractal->mlx_connection);
	}
	fractal->image.pixels_ptr = mlx_get_data_addr(fractal->image.img_ptr,
			&fractal->image.bpp, &fractal->image.line_len,
			&fractal->image.endian);
	if (NULL == fractal->image.pixels_ptr)
	{
		mlx_destroy_image(fractal->mlx_connection, fractal->image.img_ptr);
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		ft_error(fractal->mlx_connection);
	}
	event_init(fractal);
}
