#include "fractol.h"

/*
 * Maps a value from one range to another.
 * Example: mapping pixel coordinate (0..800) to complex plane (-2..+2).
 */
double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

/*
 * Adds two complex numbers.
 * (a + bi) + (c + di) = (a+c) + (b+d)i
 */
t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

/*
 * Squares a complex number.
 * (x + yi)^2 = x^2 + 2xyi + (yi)^2 = x^2 - y^2 + 2xyi
 * Real part: x^2 - y^2
 * Imaginary part: 2xy
 */
t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
