/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:00:00 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/12 02:00:00 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal(va_list ap)
{
	long	num;
	int		len;

	num = va_arg(ap, int);
	len = ft_numlen(num);
	ft_putnbr_fd(num, 1);
	return (len);
}

int	print_hex(va_list ap, char specifier)
{
	unsigned int	num;
	int				len;

	num = va_arg(ap, unsigned int);
	len = ft_hexlen(num);
	ft_puthex_fd(num, specifier, 1);
	return (len);
}

int	print_pointer(va_list ap)
{
	unsigned long	p;
	int				len;

	p = va_arg(ap, unsigned long);
	if (p == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	len = 0;
	ft_putstr_fd("0x", 1);
	len = 2;
	ft_puthex_fd(p, 'x', 1);
	len += ft_hexlen(p);
	return (len);
}

int	print_unsigned(va_list ap)
{
	unsigned long	num;
	int				len;

	num = va_arg(ap, unsigned int);
	len = ft_numlen(num);
	ft_putunsigned_fd(num, 1);
	return (len);
}
