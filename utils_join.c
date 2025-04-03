/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:46:44 by zkharbac          #+#    #+#             */
/*   Updated: 2025/04/03 11:15:36 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	calculate_length(int argc, char **argv)
{
	int	i;
	int	len;

	len = 0;
	i = 1;
	while (i < argc)
	{
		len += ft_strlen(argv[i]);
		if (i + 1 < argc)
			len += 1;
		i++;
	}
	return (len);
}

void	fill_join_d(char *join_d, int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			join_d[k++] = argv[i][j++];
		if (i + 1 < argc)
			join_d[k++] = ' ';
		i++;
	}
	join_d[k] = '\0';
}

char	*join_arg(int argc, char **argv)
{
	char	*join_d;
	int		len;

	len = calculate_length(argc, argv);
	join_d = malloc(len + 1);
	if (!join_d)
		return (NULL);
	fill_join_d(join_d, argc, argv);
	return (join_d);
}
