#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == 65307) // ESC key
		close_handler(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4) // Scroll UP -> Zoom IN
	{
		fractal->zoom *= 0.95;
	}
	else if (button == 5) // Scroll DOWN -> Zoom OUT
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}
