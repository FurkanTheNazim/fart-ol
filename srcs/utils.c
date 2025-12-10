/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 07:41:59 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/10 07:42:51 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s1 == *s2 && --n)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static double	get_double_part(char *s, double result)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 1.0;
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			divisor *= 10.0;
			fraction = fraction * 10.0 + (*s - '0');
			s++;
		}
		result += fraction / divisor;
	}
	return (result);
}

double	atodbl(char *s)
{
	long	integer_part;
	double	result;
	double	sign;

	integer_part = 0;
	result = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		integer_part = integer_part * 10 + (*s - '0');
		s++;
	}
	result = (double)integer_part;
	result = get_double_part(s, result);
	return (result * sign);
}
