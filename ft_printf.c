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

int	print_cases(char c, va_list args)
{
	int	n_char;

	n_char = 0;
	if (c == '%')
		n_char = ft_putchar('%');
	else if (c == 'c')
		n_char = ft_putchar(va_arg(args, int));
	else if (c == 'c')
		n_char = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		n_char = 0;//ft_putstr_non_printable(va_arg(args, unsigned long));
	else if (c == 'd')
		n_char = ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		n_char = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		n_char = ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		n_char = ft_putnbr_base(va_arg(args, unsigned int), "01234567890abcdef");
	else if (c == 'X')
        n_char = ft_putnbr_base(va_arg(args, unsigned int), "01234567890ABCDEF");
	return (n_char);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int	n_char;
	int	i;

	va_start(args, s);
	n_char = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			n_char += print_cases(s[i + 1], args);
			i += n_char;
		}
		else
			ft_putchar(s[i]);
		++n_char;
	}
	va_end(args);
	return (n_char);
}
