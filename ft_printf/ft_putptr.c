/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:39:41 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/16 14:59:40 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int			len;
	long		address;

	address = (unsigned long)ptr;
	len = 0;
	len += write(1, "0x", 2);
	if (!address)
		return (len + write(1, "0", 1));
	return (len + ft_puthex(address, 0));
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
