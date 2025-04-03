/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:41:40 by zkharbac          #+#    #+#             */
/*   Updated: 2025/04/03 11:14:04 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

static char	*allocate_word(char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static int	fill_words(char **result, char *s)
{
	int	i;
	int	k;
	int	start;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != ' ')
			i++;
		result[k] = allocate_word(s, start, i);
		if (!result[k])
			return (free_split(result), 0);
		k++;
	}
	result[k] = NULL;
	return (1);
}

char	**ft_split(char *s)
{
	char	**result;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!fill_words(result, s))
		return (NULL);
	return (result);
}
