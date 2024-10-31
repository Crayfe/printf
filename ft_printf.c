/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/10/31 15:16:54 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_ptr(unsigned long ptr)
{
	int	n;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	n = 0;
	n += ft_putstr("0x");
	n += ft_putnbr_base(ptr, "0123456789abcdef");
	return (n);
}

static int	print_cases(char c, va_list args)
{
	int	n;

	n = 0;
	if (c == '%')
		n = ft_putchar('%');
	else if (c == 'c')
		n = ft_putchar(va_arg(args, int));
	else if (c == 's')
		n = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		n = print_ptr(va_arg(args, unsigned long));
	else if (c == 'd')
		n = ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		n = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		n = ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		n = ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		n = ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (n);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		n_char;
	int		i;

	va_start(args, s);
	n_char = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			n_char += print_cases(s[i++ + 1], args);
		else if (s[i] == '%' && !s[i + 1])
			return (n_char);
		else
		{
			ft_putchar(s[i]);
			++n_char;
		}
		++i;
	}
	va_end(args);
	return (n_char);
}
