/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2026/05/30 21:12:14 by alfeofan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	word_count(const char *s, char c)
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

static char	*fill_word(const char *str, int len)
{
	char	*word;
	int		i;

	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	word_len(char const *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static int	process_words(char const *s, char c, char **result)
{
	int	j;
	int	len;

	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		if (len > 0)
		{
			result[j] = fill_word(s, len);
			if (!(result[j]))
			{
				free_matrix(result);
				return (0);
			}
			j++;
			s += len;
		}
	}
	result[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!process_words(s, c, result))
		return (NULL);
	return (result);
}
