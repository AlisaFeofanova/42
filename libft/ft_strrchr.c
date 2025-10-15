/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/10 20:04:49 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
Функция ищет последнее вхождение символа c в строке s
Возвращает:
Указатель на последнее вхождение символа c
Или NULL, если символ не найден
*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return ((char *)last);
}
/*
#include <stdio.h>

int main(void)
{
    char str[] = "Alisa Feofanova";
    char *p = ft_strrchr(str, 'o');

    if (p)
        printf("Последнее 'o' найдено по адресу: %ld\n",  p - str);
    else
        printf("Не найдено\n");

    return 0;
}
*/
