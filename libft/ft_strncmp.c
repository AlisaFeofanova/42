/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/10 20:04:49 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
The strncmp() function compares not more than n characters.
  Because strncmp() is designed for
     comparing strings rather than binary data, characters
 that appear after a ‘\0’ character are
     not compared.
The strcmp() and strncmp() functions return an integer
 greater than, equal to, or less than 0,
     according as the string s1 is greater than,
 equal to, or less than the string s2.  The
     comparison is done using unsigned characters,
 so that ‘\200’ is greater than ‘\0’.
*/
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i]
		&& i < n - 1 && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>

int main(void)
{
    char s1[] = "123499999";
    char s2[] = "123456789";
    int res;

    res = ft_strncmp(s1, s2, 5);

    if (res > 0)
        printf("s1 > s2");
    else if (res < 0)
        printf("s1 < s2");
    else
        printf("s1 == s2");
    return 0;
}
*/
