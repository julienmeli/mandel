/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeli <jmeli@student.42luxembourg.lu>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:44:21 by jmeli             #+#    #+#             */
/*   Updated: 2025/01/02 12:22:49 by jmeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	initialize_minilibx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "fractol");
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
}

void	initialize(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFCBE11;
	fractal->zoom = 300;
	fractal->offset_x = -2.00; //-2.1
	fractal->offset_y = -1.25; // -1.5
	if (ft_strncmp(fractal->name, "Julia", 5) == 0)
	{
		fractal->cx = -0.80;
		fractal->cy = 0.176;
		fractal->offset_x = -1.60;
		fractal->offset_y = -1.50;
	}
	fractal->number_of_iterations = ITERATIONS;
}
