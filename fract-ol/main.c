/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:33:32 by ylabser           #+#    #+#             */
/*   Updated: 2025/06/10 20:56:11 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] <= 32)
		i++;
	if ((str[i] == '-' || str[i] == '+' || str[i] == '.') && str[i + 1] == '\0')
		return (1);
	else if ((str[i] == '+' || str[i] == '-') && str[i + 1] == '.')
		return (1);
	else
		return (0);
}

static int	valide_input(char *str)
{
	int	i;

	i = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (ft_strlen(str) != i || is_digit(str))
		return (1);
	else
		return (0);
}

static double	atodbl(char *str)
{
	double	nbr_int;
	double	nbr_frc;
	double	pow;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	nbr_int = 0;
	nbr_frc = 0;
	pow = 1;
	while (str[i] <= 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr_int *= 10;
		nbr_int += str[i] - '0';
		i++;
	}
	if ('.' == str[i])
		i++;
	while (str[i])
	{
		pow /= 10;
		nbr_frc += (str[i] - '0') * pow;
		i++;
	}
	return (sign * (nbr_int + nbr_frc));
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((2 == ac && ft_strncmp(av[1], "mandelbrot", 10) == 0)
		|| (4 == ac && !ft_strncmp(av[1], "julia", 5)
			&& !valide_input(av[2]) && !valide_input(av[3])))
	{
		fractal.name = av[1];
		if (ft_strncmp(fractal.name, "julia", 5) == 0)
		{
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = -atodbl(av[3]);
		}
		fractal.color = 0x00090907;
		fractal.zoom = 1.0;
		fractal.iter = 100;
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_error();
	}
}
