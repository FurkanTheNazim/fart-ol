#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100

// Complex number structure
typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

// Image structure
typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

// Fractal structure
typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value; // Hypotenuse
	int		iterations_definition; // Value to determine rendering quality
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;

// Function Prototypes

// init.c
void	fractal_init(t_fractal *fractal);

// render.c
void	fractal_render(t_fractal *fractal);

// math_utils.c
double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

// events.c
int		key_handler(int keysym, t_fractal *fractal);
int		close_handler(t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);

// utils.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
double	atodbl(char *s);

#endif
