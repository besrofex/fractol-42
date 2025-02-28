/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:33:32 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/27 17:52:03 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((2 == ac && ft_strncmp(av[1], "mandelbrot", 10) == 0)
		|| (4 == ac && ft_strncmp(av[1], "Julia", 5) == 0))
	{
		fractal.name = av[1];
		if (ft_strncmp(fractal.name, "julia", 5) == 0)
		{
			fractal.shift_x = atodbl(av[2]);
			fractal.shift_y = atodbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}