/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:28:16 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/28 18:53:42 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	free(fractal->mlx_connection);
	exit(0);
}

int	key_handler(int key, void *param)
{
	t_fractal *fractal = (t_fractal *)param;
	if (key == 65307)
		close_handler(fractal);
	if (key == 65361)
		fractal->shift_x += fractal->zoom * 0.5;
	else if (key == 65363)
		fractal->shift_x -= fractal->zoom * 0.5;
	else if (key == 65362)
		fractal->shift_y -= fractal->zoom * 0.5;
	else if (key == 65364)
		fractal->shift_y += fractal->zoom * 0.5;
	fractal_render(fractal);
	return (0);
}