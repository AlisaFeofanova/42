/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:39:41 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/16 14:59:40 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
/*
int main(void)
{
	int count;
    char digit;

	write(1, "Test 1: ", 8);
	count = ft_putchar('h');
	write(1, " | printed: ", 12);
	digit = count + '0';
    write(1, &digit, 1);
	write(1, "\n", 1);

	write(1, "Test 2: ", 8);
	count = ft_putchar('e');
	write(1, " | printed: ", 12);
	digit = count + '0';
    write(1, &digit, 1);
	write(1, "\n", 1);

	write(1, "Test 3: ", 8);
	count = ft_putchar('l');
	write(1, " | printed: ", 12);
	digit = count + '0';
    write(1, &digit, 1);
	write(1, "\n", 1);

	write(1, "Test 4: ", 8);
	count = ft_putchar('o');
	write(1, " | printed: ", 12);
	digit = count + '0';
    write(1, &digit, 1);
	write(1, "\n", 1);

	write(1, "Test 5: ", 8);
	count = ft_putchar('0');
	write(1, " | printed: ", 12);
	digit = count + '0';
    write(1, &digit, 1);
	write(1, "\n", 1);

	write(1, "Test 6: ", 8);
	count = ft_putchar('\0');
	write(1, " | printed: ", 12);
	digit = count + '0';
    write(1, &digit, 1);
	write(1, "\n", 1);


	write(1, "Test 4: ", 8);
	count = ft_putchar(9);
	write(1, " | printed: ", 12);
	digit = count + '0';
    write(1, &digit, 1);
	write(1, "\n", 1);

	return (0);
}
*/
