/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeli <jmeli@student.42luxembourg.lu>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:39:17 by jmeli             #+#    #+#             */
/*   Updated: 2024/12/18 10:54:35 by jmeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define SIZE 700
# define ITERATIONS 42

# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
# define UP 65362
# define R 114
# define C 99
# define J 106
# define P 112
# define M 109

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define SCROLL_CLICK 3

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		number_of_iterations;
}			t_fractal;

// utils

void		color_to_pixel(t_fractal *fractal, int x, int y, int color);
int			exit_fractal(t_fractal *fractal);
void		change_number_of_iterations(t_fractal *fractal, int key_code);
void		set_random_constant(double *cx, double *cy);

// utils2
int			ft_putstr(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// initialize
void		initialize_minilibx(t_fractal *fractal);
void		initialize(t_fractal *fractal);

// hook
void		zoom(t_fractal *fractal, int x, int y, int zoom);
int			key_hook(int key_code, t_fractal *fractal);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);
int			handle_no_event(void *data);

// draw
int			draw_fractal(t_fractal *fractal);
void		calculate_mandelbrot(t_fractal *fractal);
void		draw_mandelbrot(t_fractal *fractal);
void		draw_julia(t_fractal *fractal);

#endif
