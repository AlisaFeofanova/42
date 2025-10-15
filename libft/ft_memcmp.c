/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/10 20:04:49 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
The memcmp() function compares byte string s1 against
 byte string s2.  Both strings are assumed
     to be n bytes long.
The memcmp() function returns zero if the two strings 
are identical, otherwise returns the
     difference between the first two differing bytes 
(treated as unsigned char values, so that
     ‘\200’ is greater than ‘\0’, for example). 
 Zero-length strings are always identical.  This
     behavior is not required by C and portable code
 should only depend on the sign of the returned
     value.
*/
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (ss1[i] && ss2[i] && i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	if (i < n)
		return (ss1[i] - ss2[i]);
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
    char s1[] = "123455999";
    char s2[] = "123456789";
    int res;

    res = ft_memcmp(s1, s2, 6);

    if (res > 0)
        printf("s1 > s2");
    else if (res < 0)
        printf("s1 < s2");
    else
        printf("s1 == s2");
    return 0;
}
*/
