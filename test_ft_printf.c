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
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = malloc(1);
    int len = 0;
    len = ft_printf("Me llamo Iñigo Montoya\n");
    printf("ft len: %i\n", len);
    len = printf("Me llamo Iñigo Montoya\n");
    printf("len: %i\n", len);
    len = ft_printf("Hola. Me llamo %s. Mataste a mi padre. Prepárate a morir %c\n", "Iñigo Montoya", 'x');
    printf("ft len: %i\n", len);
    len = printf("Hola. Me llamo %s. Mataste a mi padre. Prepárate a morir %c\n", "Iñigo Montoya", 'x');
    printf("len: %i\n", len);
    len = ft_printf("Numero: %i, otro numero: %u y otro numero %d\n", 99, 43, 1024);
    printf("ft len: %i\n", len);
    len = printf("Numero: %i, otro numero: %u y otro numero %d\n", 99, 43, 1024);
    printf("len: %i\n", len);
    len = ft_printf("hex: %x\n", 933);
    printf("ft len: %i\n", len);
    len = ft_printf("HEX: %X\n", 933);
    printf("ft len: %i\n", len);
    len = printf("hex: %x\n", 933);
    printf("len: %i\n", len);
    len = printf("HEX: %X\n", 933);
    printf("len: %i\n", len);
    len = ft_printf("Puntero: %p\n", ptr);
    printf("ft len: %i\n", len);
    len = printf("Puntero: %p\n", ptr);
    printf("len: %i\n", len);
    free(ptr);
    return (0);
}