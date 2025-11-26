#include "ft_printf.h"

void	ft_puthex_fd(unsigned long n, char specifier, int fd)
{
	char	*base;
	if (specifier == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";

	if (n >= 16)
		ft_puthex_fd(n / 16, specifier, fd);
	ft_putchar_fd(base[n % 16], fd);
}