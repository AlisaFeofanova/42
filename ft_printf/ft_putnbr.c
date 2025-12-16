/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:39:41 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/16 14:59:40 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nbr;
	char	c;
	int		count;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	c = (nbr % 10) + 48;
	count += write(1, &c, 1);
	return (count);
}
/*
int main(void)
{
	int count;

	write(1, "Test 1: ", 8);
	count = ft_putnbr(42);
	write(1, " | printed: ", 12);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "Test 2: ", 8);
	count = ft_putnbr(-123456);
	write(1, " | printed: ", 12);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "Test 3: ", 8);
	count = ft_putnbr(0);
	write(1, " | printed: ", 12);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "Test 4: ", 8);
	count = ft_putnbr(-2147483648);
	write(1, " | printed: ", 12);
	ft_putnbr(count);
	write(1, "\n", 1);

	return (0);
}
*/
