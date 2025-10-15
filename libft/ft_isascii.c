/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:56:59 by alfeofan          #+#    #+#             */
/*   Updated: 2025/09/29 14:33:36 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
int		ft_isascii(char c)
{
	if(c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

#include <stdio.h>
 
int main(void)
{
	int i = 0;

	char str[] = "af€qf&.1231)(*&^#!";
 	
	while (str[i])
	{
		if (ft_isascii(str[i]))
			printf("The character is %c\n", str[i]);
		else
			printf("Cannot be represented by an ASCII character\n");
		i++;
	}
	return 0;
}
