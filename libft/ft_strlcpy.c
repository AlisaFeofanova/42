/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/10 20:04:49 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
Функция strlcpy копирует строку из src в dest,
гарантируя, что в dest не произойдёт переполнения буфера
и всегда будет '\0' в конце (если size > 0).
Возвращает полную длину src.
*/
#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
/*
#include <stdio.h>

int main(void)
{
	char src[] = "Hello, World!";
	char dest[6];
	unsigned int len;

	len = ft_strlcpy(dest, src, sizeof(dest));
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);
	printf("src length: %u\n", len);

	return(0);
}
*/
