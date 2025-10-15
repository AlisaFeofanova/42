/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/10 20:04:49 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
The strnstr() function locates the first occurrence of the
 null-terminated string needle in the
     string haystack, where not more than len characters
 are searched.  Characters that appear after
     a ‘\0’ character are not searched.  Since the strnstr() 
function is a FreeBSD specific API, it
     should only be used when portability is not a concern.
If needle is an empty string, haystack is returned; if needle
 occurs nowhere in haystack, NULL
     is returned; otherwise a pointer to the first character
 of the first occurrence of needle is
     returned.
*/
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;
	char	*n;

	i = 0;
	h = (char *)haystack;
	n = (char *)needle;
	if (*n == '\0')
		return ((char *)h);
	while (h[i] && i < len)
	{
		j = 0;
		while (h[i + j] && n[j]
			&& h[i + j] == n[j]
			&& (i + j) < len)
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main(void)
{
    char haystack[] = "Alisa Feofanova";
    char needle[] = "Feof";
    char *res;

    res = ft_strnstr(haystack, needle, 3);
    printf("Found: \"%s\"\n", res);
    return (0);
}
*/
