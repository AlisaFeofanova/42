/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:50:13 by alfeofan          #+#    #+#             */
/*   Updated: 2025/09/29 13:56:20 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
int		ft_isalnum(char c)
{
	if((c >= 'A' && c <= 'Z')
	 || (c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int main ()
{
	int i;
	char str[]= "Alisa+_)6433/&%$@(&#";
	i=0;
	while(str[i])
	{
		if (ft_isalnum(str[i])) printf ("character %c is alphanumeric\n",str[i]);
     	else printf ("character %c is not alphanumeric\n",str[i]);
     	i++;
	}
  return 0;
}*/

