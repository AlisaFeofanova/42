/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/10 20:04:49 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
The strdup() function allocates sufficient memory 
for a copy of the string s1, does the copy,
     and returns a pointer to it.  The pointer may 
subsequently be used as an argument to the
     function free(3).

     If insufficient memory is available, NULL is
 returned and errno is set to ENOMEM.
*/
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		len;
	char		*dup;
	char		*src;

	i = 0;
	len = 0;
	src = (char *)s1;
	while (src[len])
		len++;
	dup = malloc(len + 1);
	if (!dup)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include<stdio.h>

int main(void)
{
    char *name = "Alisa";
    char *copy = ft_strdup(name);

    if (!copy)
    {
        perror("ft_strdup failed");
        return (1);
    }

    printf("Original: %s\n", name);
    printf("Copy:     %s\n", copy);

    free(copy);

    return (0);
}
*/
