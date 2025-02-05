/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeli <jmeli@student.42luxembourg.lu>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:31:41 by jmeli             #+#    #+#             */
/*   Updated: 2024/12/18 11:19:31 by jmeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	instructions(void)
{
	ft_putstr("Key M to decrease iterations\nKey P to increase iterations\n");
	ft_putstr("Key J to change Julia set variables\n");
	ft_putstr("Key C to change colors\n");
	ft_putstr("Key R to reset the set\n");
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc != 2 || ((ft_strncmp(argv[1], "Mandelbrot", 10) != 0)
			&& (ft_strncmp(argv[1], "Julia", 5) != 0)))
	{
		ft_putstr("Fractol program works as follows:\n");
		ft_putstr("./fractol <type of fractal>\n");
		ft_putstr("The 2 (case sensitive) types of fractal are:\n");
		ft_putstr("Mandelbrot\nJulia\n");
		return (1);
	}
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (ft_putstr("Memory allocation failed.\n"));
	instructions();
	fractal->name = argv[1];
	initialize(fractal);
	initialize_minilibx(fractal);
	mlx_loop_hook(fractal->mlx, &handle_no_event, &fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	mlx_loop(fractal->mlx);
	return (0);
}
