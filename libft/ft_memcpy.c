/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/10 20:04:49 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
Копирует ровно n байт из области памяти src в область
 памяти dest.
//signed char → диапазон от -128 до 127 
 Используется если нужны маленькие отрицательные числа
//unsigned char → диапазон от 0 до 255  Используется 
для работы с "сырыми" данными (байтами): изображения, файлы, память.
//Ключевое слово restrict -  указатель — единственный
 способ доступа к этой области памяти в пределах
 своей "жизни". ДЛЯ ОПТИМИЗАЦИИ
*/
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
    char src[] = "Alisa Feofanova";
    char dest[20];

    ft_memcpy(dest, src, 9);  
    printf("%s\n", dest);  
    return 0;
}
*/
