/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:34:53 by alfeofan          #+#    #+#             */
/*   Updated: 2025/09/29 14:43:40 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int main ()
{
  int i=0;
  char str[]="first line \n second line \n\0";
  
 while (str[i])
	{
		if (ft_isprint(str[i]))
			printf("The character is %c\n", str[i]);
		else
			printf("Cannot be printed\n");
		i++;
	}
	return 0;

}*/
