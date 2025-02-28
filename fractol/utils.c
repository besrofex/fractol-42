/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:35:04 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/27 14:50:03 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (NULL == s1 || NULL == s2 || n <= 0)
		retunr (0);
	while (i < n && s1[i] == s2[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

double	atodbl(char *str)
{
	double	nbr;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (sign * nbr);
}