/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:39:41 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/16 14:59:40 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex(unsigned long n, int format)
{
	int		count;
	char	*base;

	count = 0;
	if (format == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	count += ft_putchar(base[n % 16]);
	return (count);
}
/*
int main(void)
{
	int count;

	write(1, "Test 1: ", 8);
	count = ft_puthex(42, 0);
	write(1, " | printed: ", 12);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "Test 2: ", 8);
	count = ft_puthex(-123456, 1);
	write(1, " | printed: ", 12);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "Test 3: ", 8);
	count = ft_puthex(0, 1);
	write(1, " | printed: ", 12);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "Test 4: ", 8);
	count = ft_puthex(-2147448, 0);
	write(1, " | printed: ", 12);
	ft_putnbr(count);
	write(1, "\n", 1);

	return (0);
}
*/
