/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeli <jmeli@student.42luxembourg.lu>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:51:12 by jmeli             #+#    #+#             */
/*   Updated: 2024/12/18 08:18:12 by jmeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractal->offset_x = ((x / fractal->zoom + fractal->offset_x) - (x
					/ (fractal->zoom * zoom_level)));
		fractal->offset_y = ((y / fractal->zoom + fractal->offset_y) - (y
					/ (fractal->zoom * zoom_level)));
		fractal->zoom = fractal->zoom * zoom_level;
	}
	if (zoom == -1)
	{
		fractal->offset_x = ((x / fractal->zoom + fractal->offset_x) - (x
					/ (fractal->zoom / zoom_level)));
		fractal->offset_y = ((y / fractal->zoom + fractal->offset_y) - (y
					/ (fractal->zoom / zoom_level)));
		fractal->zoom = fractal->zoom / zoom_level;
	}
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit_fractal(fractal);
	else if (key_code == UP)
		fractal->offset_y = fractal->offset_y - 42 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y = fractal->offset_y + 42 / fractal->zoom;
	else if (key_code == LEFT)
		fractal->offset_x = fractal->offset_x - 42 / fractal->zoom;
	else if (key_code == RIGHT)
		fractal->offset_x = fractal->offset_x + 42 / fractal->zoom;
	else if (key_code == R)
		initialize(fractal);
	else if (key_code == C)
		fractal->color = fractal->color + (255 * 255 * 255) / 100;
	else if (key_code == M || key_code == P)
		change_number_of_iterations(fractal, key_code);
	else if (key_code == J)
		set_random_constant(&fractal->cx, &fractal->cy);
	draw_fractal(fractal);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
	{
		zoom(fractal, x, y, 1);
	}
	else if (mouse_code == SCROLL_DOWN)
	{
		zoom(fractal, x, y, -1);
	}
	draw_fractal(fractal);
	return (1);
}

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}
