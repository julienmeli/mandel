/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeli <jmeli@student.42luxembourg.lu>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:23:40 by jmeli             #+#    #+#             */
/*   Updated: 2024/12/18 08:16:12 by jmeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	set_random_constant(double *cx, double *cy)
{
	*cx = (double)rand() / RAND_MAX * 3.0 - 1.5;
	*cy = (double)rand() / RAND_MAX * 3.0 - 1.5;
}

void	color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	char	*dest;

	dest = fractal->pointer_to_image + (y * fractal->size_line + x
			* (fractal->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_image(fractal->mlx, fractal->image);
	free(fractal->mlx);
	free(fractal);
	exit(1);
}

void	change_number_of_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == M)
	{
		if (fractal->number_of_iterations > 42)
			fractal->number_of_iterations = fractal->number_of_iterations - 42;
	}
	else if (key_code == P)
	{
		if (fractal->number_of_iterations < 4200)
			fractal->number_of_iterations = fractal->number_of_iterations + 42;
	}
}
