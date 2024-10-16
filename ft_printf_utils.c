/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:38:14 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/10/11 12:56:28 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, s + i, 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	unsigned int	aux_int;
	int		chars;

	aux_int = 0;
	chars = 0;
	if (n < 0)
	{
		ft_putchar('-');
		aux_int = -1 * n;
		++chars;
	}
	else
		aux_int = n;
	if (aux_int > 9)
		chars += ft_putnbr(aux_int / 10);
	ft_putchar(aux_int % 10 + '0');
	++chars;
	return (chars);
}

int	ft_putnbr_base(int n, char *base)
{
	unsigned int	aux_int;
	int		chars;

	aux_int = 0;
	chars = 0;
	if (n < 0)
	{
		ft_putchar('-');
		aux_int = -1 * n;
		++chars;
	}
	else
		aux_int = n;
	if (aux_int >= (unsigned int)ft_strlen(base))
		chars += ft_putnbr_base(aux_int / ft_strlen(base), base);
	ft_putchar(base[aux_int % ft_strlen(base)]);
	++chars;
	return (chars);
	
}
