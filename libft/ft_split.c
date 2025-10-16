/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/16 02:48:35 by alfeofan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

char    *fill_word(const char *str, int start, int end)
{
    char *word;

    word = malloc((end - start + 1) * sizeof(char));
    if (!word)
        return (NULL);
    ft_strlcpy(word, str + start, end - start + 1);
    return (word);
}


void    *ft_free(char **strs, int count)
{
    int i;
    
    i = 0;
    while (i < count)
    {
        free(strs[i]);
        i++;
    }
    free(strs);
    return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		start;

	if (!s || !c)
		return (NULL);
	result = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			result[j] = fill_word(s, start, i);
            if (!(result[j]))
                return (ft_free(result, j));
            j++;
		}
	}
	result[j] = NULL;
	return (result);
}







 61 int word_len(char const *str, char c)
 62 {
 63     int     len;
 64 
 65     len = 0;
 66     while (s[len] == c)
 67             len++;
 68     while (s[len] && s[len] != c)
 69             len++;
 70     return (len);
 71 }
 72 
 73 char    **ft_split(char const *s, char c)
 74 {
 75     char    **result;
 76     int     j;
 77     int end;
 78 
 79     if (!s || !c)
 80         return (NULL);
 81     result = malloc((word_count(s, c) + 1) * sizeof(char *));
 82     if (!result)
 83         return (NULL);
 84     j = 0;
 85     while (*s)
 86     {   
 87         end = word_len(s, c);
 88         result[j] = fill_word(s, 0, end);
 89         if (!(result[j]))
 90             return (ft_free(result, j));
 91         j++;
 92         s += end;
 93     }
 94     result[j] = NULL;
 95     return (result);
 96 }

