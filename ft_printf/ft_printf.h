/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:59:12 by marvin            #+#    #+#             */
/*   Updated: 2025/07/11 21:59:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_numlen(long n);
int		ft_hexlen(unsigned long n);
void	ft_puthex_fd(unsigned long n, char specifier, int fd);
void	ft_putunsigned_fd(unsigned int n, int fd);

int		print_char(va_list ap);
int		print_string(va_list ap);
int		print_decimal(va_list ap);
int		print_unsigned(va_list ap);
int		print_hex(va_list ap, char specifier);
int		print_pointer(va_list ap);
int		print_percent(void);

int		ft_format_handler(char specifier, va_list ap);
int		ft_printf(const char *format, ...);

#endif