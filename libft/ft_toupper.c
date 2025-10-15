/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/10 20:04:49 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
Функция toupper переводит букву в верхний регистр (заглавную),
если она — строчная латинская ('a'–'z').
Если символ не буква — он не меняется.
*/
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>

int main(void)
{
    char c1 = 'a';
    char c2 = '!';
    char c3 = 'Z';

    printf("%c -> %c\n", c1, ft_toupper(c1)); 
    printf("%c -> %c\n", c2, ft_toupper(c2));
    printf("%c -> %c\n", c3, ft_toupper(c3)); 

    return 0;
}
*/
