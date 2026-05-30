/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:06:17 by alfeofan          #+#    #+#             */
/*   Updated: 2026/02/11 18:45:13 by alfeofan       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex(unsigned long n, int format)
{
	int			count;
	const char	*base;

	count = 0;
	if (format == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += hex(n / 16, format);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int				len;
	unsigned long	address;

	address = (unsigned long)ptr;
	len = 0;
	if (!address)
		return (write(1, "(nil)", 5), 5);
	len += write(1, "0x", 2);
	return (len + hex(address, 0));
}

/*
int main(void) {
    int *ptr;
    int *ptr2;
    int x;
    int y;
    
    x = 10;
    y = 10;
    ptr = &x;
    ptr2 = &y;
    
    ft_putptr(ptr);
    write(1, "\n", 1);
    ft_putptr(ptr2);
    write(1, "\n", 1);
    
    return (0);
}
*/
