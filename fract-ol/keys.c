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

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	free(fractal->mlx_connection);
	exit(1);
}

int	key_handler(int key, void *param)
{
	t_fractal *fractal = (t_fractal *)param;
	if (key == 53)
		close_handler(fractal);
	else if (key == 11)
		fractal->zoom = 1;
	else if (key == 69)
		fractal->iter += 10;
	else if (key == 78)
		fractal->iter -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int key,int x, int y, void *param)
{
	t_fractal *fractal = (t_fractal *)param;
	(void)x;
	(void)y;
	if (key == 4)
	fractal->zoom *= 1.10;
	else if(key == 5)
		fractal->zoom *= 0.90;
	fractal_render(fractal);
	return (0);
}