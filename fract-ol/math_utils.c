/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:40:17 by ylabser           #+#    #+#             */
/*   Updated: 2025/06/10 21:01:52 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	square_complex(t_complex c)
{
	t_complex	z;

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

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s1[i] == s2[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
