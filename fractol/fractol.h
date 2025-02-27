/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:43:49 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/27 17:12:07 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOLH_H
#define FRACTOLH_H

# include <unistd.h>
# include <stdlib.h>
# include "mlx/mlx.h"

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int	bpp;
	int	endian;
	int	line_len;	
}					t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	image;
}					t_fractal;

// init
void	fractal_init(t_fractal *fractal);

// str_utils
int	ft_strncmp(const char *s1, const char *s2, int n);

#endif