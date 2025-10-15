/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/10 20:04:49 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
Эта функция копирует n байт из области src в область dest,
и безопасна, даже если эти области пересекаются (в отличие от memcpy).

Перекрытие (или overlap) — это когда часть памяти, в которую ты копируешь (dest),
находится внутри области, из которой ты копируешь (src).
Или наоборот — часть src находится внутри dest.
*/
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	if (d == s)
		return (dst);
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (len--)
			d[len] = s[len];
	}
	return (dst);
}
/*
#include <stdio.h>

int main(void)
{
    char str[] = "123456789";
    ft_memmove(str + 2, str, 6); 
    printf("%s\n", str);      
}
*/
