/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:43:49 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/28 21:46:27 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOLH_H
#define FRACTOLH_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

typedef struct s_complex
{
	double	x;
	double	y;
}					t_complex;

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
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}					t_fractal;

// init
void	fractal_init(t_fractal *fractal);

// render
void fractal_render(t_fractal *fractal);

// math utils
t_complex	square_complex(t_complex c);
t_complex	sum_complex(t_complex a, t_complex b);
double	map(double value, double new_min, double new_max, double old_min, double old_max);

// str_utils
int	ft_strncmp(const char *s1, const char *s2, int n);
double	atodbl(char *str);

// moves
int	key_handler(int key, void *param);
void	close_handler(t_fractal *fractal);

#endif