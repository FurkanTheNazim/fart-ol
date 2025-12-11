/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 07:41:46 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/12 01:42:02 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (keysym == 65307)
		close_handler(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	mouse_re = (map(x, (t_map){-2, 2, 0, WIDTH}) * fractal->zoom)
		+ fractal->shift_x;
	mouse_im = (map(y, (t_map){2, -2, 0, HEIGHT}) * fractal->zoom)
		+ fractal->shift_y;
	if (button == 4)
		zoom_factor = 0.95;
	else if (button == 5)
		zoom_factor = 1.05;
	else
		return (0);
	fractal->shift_x = mouse_re - (mouse_re - fractal->shift_x) * zoom_factor;
	fractal->shift_y = mouse_im - (mouse_im - fractal->shift_y) * zoom_factor;
	fractal->zoom *= zoom_factor;
	fractal_render(fractal);
	return (0);
}
