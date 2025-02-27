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