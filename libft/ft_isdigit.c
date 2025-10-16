/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:43:11 by alfeofan          #+#    #+#             */
/*   Updated: 2025/09/29 12:49:38 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
 
 int main ()
 {
   int i=0;
   char str[]="Alisa+_)6433/&%$@(&#";
   while (str[i])
   {
     if (ft_isdigit(str[i])) printf ("character %c is digit\n",str[i]);
     else printf ("character %c is not digit\n",str[i]);
     i++;
   }
   return 0;
}*/
