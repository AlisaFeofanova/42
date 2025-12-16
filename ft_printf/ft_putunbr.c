/*
принимать одно значение unsigned int n;
выводить его по цифрам;
возвращать количество выведенных символов (для ft_printf).
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:39:41 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/16 14:59:40 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr(n / 10);
	count += ft_putchar((n % 10) + 48);
	return (count);
}
/*
int main(void)
{
	int count;

	write(1, "Test 1: ", 8);
	count = ft_putunbr(42);
	write(1, " | printed: ", 12);
	ft_putunbr(count);
	write(1, "\n", 1);

	write(1, "Test 2: ", 8);
	count = ft_putunbr(-123456);
	write(1, " | printed: ", 12);
	ft_putunbr(count);
	write(1, "\n", 1);

	write(1, "Test 3: ", 8);
	count = ft_putunbr(0);
	write(1, " | printed: ", 12);
	ft_putunbr(count);
	write(1, "\n", 1);

	write(1, "Test 4: ", 8);
	count = ft_putunbr(-2147483648);
	write(1, " | printed: ", 12);
	ft_putunbr(count);
	write(1, "\n", 1);

	return (0);
}
*/
