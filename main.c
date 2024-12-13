#include "../include/minilibx-linux/mlx.h"

int	main()
{
	void	*mlx_ptr;
	void	*mlx_window;

	mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(mlx_ptr, 100, 100, "Julien's window");
	mlx_loop(mlx_ptr);
}
