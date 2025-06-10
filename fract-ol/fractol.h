/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:43:49 by ylabser           #+#    #+#             */
/*   Updated: 2025/06/10 21:35:15 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "./mlx.h"

typedef struct s_complex
{
	double	x;
	double	y;
}					t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;	
}					t_img;

typedef struct s_fractal
{
	char				*name;
	void				*mlx_connection;
	void				*mlx_window;
	t_img				image;
	unsigned int		color;
	double				zoom;
	double				julia_x;
	double				julia_y;
	int					iter;
}					t_fractal;

// init
void		fractal_init(t_fractal *fractal);

// render
void		fractal_render(t_fractal *fractal);

// math utils
t_complex	square_complex(t_complex c);
t_complex	sum_complex(t_complex a, t_complex b);
int			ft_strlen(char *str);
int			ft_strncmp(const char *s1, const char *s2, int n);

// moves
int			key_handler(int key, void *param);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int key, int x, int y, void *param);

#endif