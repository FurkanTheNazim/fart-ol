#include "ft_printf.h"

int ft_format_handler(char specifier, va_list ap)
{
    if (specifier == 'c')
        return (print_char(ap));
    else if (specifier == 's')
        return (print_string(ap));
    else if (specifier == 'd' || specifier == 'i')
        return (print_decimal(ap));
    else if (specifier == 'p')
        return (print_pointer(ap));
    else if (specifier == 'x' || specifier == 'X')
        return (print_hex(ap, specifier));
    else if (specifier == 'u')
        return (print_unsigned(ap));
    else if(specifier == '%')
        return (print_percent());
    return (0);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int i;
    int count;
    
    va_start(ap, format);
    count = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            count += ft_format_handler(format[i], ap);
        }
        
        else
        {
            ft_putchar_fd(format[i], 1);
            count++;
        }
        i++;
    }
    va_end(ap);
    return(count);
}
