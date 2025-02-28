/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:35:04 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/28 16:58:44 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	while (i < n && s1[i] == s2[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

double	atodbl(char *str)
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
	while (str[i] <= '0' && str[i] <= '9')
	{
		nbr_int *= 10;
		nbr_int += str[i] - '0';
		i++;
	}
	if ('.' == str[i])
		i++;
	while (str[i])
	{
		nbr_frc /= 10;
		nbr_frc += (str[i] - '0') * pow;
		i++;
	}
	return (sign * (nbr_int + nbr_frc));
}