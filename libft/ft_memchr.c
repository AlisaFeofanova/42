/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/10 20:04:49 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
The memchr() function locates the first occurrence
 of c (converted to an unsigned char) in
     string s.
The memchr() function returns a pointer to the byte
 located, or NULL if no such byte exists
     within n bytes.
*/
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (*p && i < n)
	{
		if (*p == (unsigned char)c)
			return ((char *)p);
		p++;
		i++;
	}
	return (NULL);
}
/*
 #include <stdio.h>

int main(void)
{
    char str[] = "Alisa Feofanova";
    char *p;

    p = ft_memchr(str, 'a', 10);
    if (p)
        printf("Found: '%c' at position %ld\n", *p, p - str);
    else
        printf("Not found!\n");

    return 0;
}
*/
