/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/15 19:36:06 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t		len;
	int			i;
	
	len = ft_strlen(s1) + ft_strlen(s2);
	if (len == 0)
	{
		result = malloc(1);
		result[0] = '\0';
		return (result);
	}
	result = malloc(len * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '\0';
	ft_strcat(result, s1);
	ft_strcat(result, s2);
	return (result);
}
