/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:40:17 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/28 16:56:29 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	square_complex(t_complex c)
{
	t_complex z;

	z.x = (c.x * c.x) - (c.y * c.y);
	z.y = 2 * c.x * c.y;
	return (z);
}

t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex	z;

	z.x = a.x + b.x;
	z.y = a.y + b.y;
	return (z);
}

double	map(double value, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (value - old_min) / (old_max - old_min) + new_min);
}