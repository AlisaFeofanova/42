/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/10 20:04:49 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
Функция strchr() ищет первое вхождение символа c
в строке str (включая символ конца строки '\0'!).

Оператор (char *) снимает константность —
он говорит компилятору:
«Да, я знаю, что s было const char *, но я уверен, что можно вернуть char *.»
*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>

int main(void)
{
    char str[] = "Alisa Feofanova";
    char *p;

    p = ft_strchr(str, 'n');
    if (p)
        printf("Found: '%c' at position %ld\n", *p, p - str);
    else
        printf("Not found!\n");

    return 0;
}
*/
