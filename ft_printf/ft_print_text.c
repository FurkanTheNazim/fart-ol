#include "ft_printf.h"

int	print_char(va_list ap)
{
	ft_putchar_fd(va_arg(ap, int), 1);
	return (1);
}

int	print_string(va_list ap)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}

int	print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
