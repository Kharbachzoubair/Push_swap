/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:41:40 by zkharbac          #+#    #+#             */
/*   Updated: 2025/01/15 15:51:28 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>  
#include <stdlib.h>  
#include <stdio.h>
void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	char	*str;
	size_t	i;

	if (count == 0 || size == 0)
		return (malloc(1));
	if (count > (size_t) - 1 / size)
		return (NULL);
	total = count * size;
	str = (char *)malloc(total);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < total)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	size;
	char	*copy;

	i = 0;
	size = ft_strlen(s1);
	copy = malloc(size + 1);
	if (copy == NULL)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
static int	count_word(char const *s, char c)
{
	int		i;
	int	count;
	int		word;

	i = 0;
	count = 0;
	while (s[i])
	{
		word = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (word == 0)
				count++;
			word = 1;
			i++;
		}
	}
	return (count);
}

static char	**free_s(char **split, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**fill_words(char **split, char const *s, char c, int word_count)
{
	int	i;
	int	j;
	int	word_start;

	i = 0;
	j = 0;
	while (s[i] && j < word_count)
	{
		word_start = 0;
		while (s[i] == c && s[i])
			i++;
		word_start = i;
		while (s[i] != c && s[i])
			i++;
		if (i > word_start)
		{
			split[j] = ft_substr(s, word_start, i - word_start);
			if (split[j] == NULL)
				return (free_s(split, j));
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_word(s, c);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	return (fill_words(split, s, c, word_count));
}
int main ()
{
	printf("%d",count_word("    help us", ' '));
}