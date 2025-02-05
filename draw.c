/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeli <jmeli@student.42luxembourg.lu>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:00:52 by jmeli             #+#    #+#             */
/*   Updated: 2025/01/02 12:36:35 by jmeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	calculate_mandelbrot(t_fractal *fractal)
{
	double	temp_x;
	int		i;

	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->number_of_iterations)
	{
		temp_x = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = temp_x;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->number_of_iterations)
		color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
	{
		color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color) * i);
	}
}

void	draw_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0;
	while (fractal->x < SIZE)
	{
		fractal->y = 0;
		while (fractal->y < SIZE)
		{
			calculate_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
}

void	calculate_julia(t_fractal *fractal)
{
	double	temp_x;
	int		i;

	i = 0;
	fractal->zx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->zy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->number_of_iterations)
	{
		temp_x = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * temp_x * fractal->zy + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->number_of_iterations)
		color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
	{
		color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color) * (i
				% 255));
	}
}

void	draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	while (fractal->x < SIZE)
	{
		fractal->y = 0;
		while (fractal->y < SIZE)
		{
			calculate_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
}

int	draw_fractal(t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "Mandelbrot", 10) == 0)
	{
		draw_mandelbrot(fractal);
	}
	else if (ft_strncmp(fractal->name, "Julia", 5) == 0)
		draw_julia(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}
