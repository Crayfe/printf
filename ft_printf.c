/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/10/02 15:46:30 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_cases(char *s, void *arg)
{
	int	printed_chars;

	printed_chars = 0;
	if (s == '%')
		write(1, "%", ++printed_chars);
	else if (s == 'c')
		printed_chars = ft_putchar((char)arg);
	else if (s == 's')
		printed_chars = ft_putstr((char *)arg);
	else if (s == 'p')
		printed_chars = ft_putstr_non_printable((char *)arg);
	else if (s == 'd')
		printed_chars = ft_putnbr((int)arg);
	else if (s == 'i')
		printed_chars = ft_putnbr((int)arg);
	else if (s == 'u')
		printed_chars = ft_putnbr((int)arg);
	else if (s == 'x')
		printed_chars = ft_putnbr_base((int)arg, "01234567890abcdef");
	else if (s == 'X')
                printed_chars = ft_putnbr_base((int *)arg, "01234567890ABCDEF");
	return (printed_chars);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int	printed_chars;

	va_start(args, s);
	printed_chars = 0;
	while (s)
	{
		if (*s == %)
		{
			printed_chars += print_cases(++s, va_arg(args, void *));
			s += printed_chars;
		}
		else
		{
			write(1, s, 1);
			++printed_chars;
			++s;
		}
	}
	va_end(args);
	return (print);
}
