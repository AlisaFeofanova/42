/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/10 20:04:49 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
Функция tolower() преобразует символ в нижний регистр,
если это заглавная латинская буква ('A'–'Z').
Если символ не буква — он не изменяется.
*/
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>

int main(void)
{
    char c1 = 'a';
    char c2 = '!';
    char c3 = 'Z';

    printf("%c -> %c\n", c1, ft_tolower(c1)); 
    printf("%c -> %c\n", c2, ft_tolower(c2));
    printf("%c -> %c\n", c3, ft_tolower(c3)); 

    return 0;
}
*/
