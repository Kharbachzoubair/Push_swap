/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:53:45 by zkharbac          #+#    #+#             */
/*   Updated: 2025/03/23 21:51:35 by zkharbac         ###   ########.fr       */
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

int	count_words(char *s)
{
	int	i;
	int	word;
	int	count;

	i = 0;
	word = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			word = 0;
		else if (word == 0)
		{
			count++;
			word = 1;
		}
		i++;
	}
	return (count);
}

int	ft_atoi(char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > 9223372036854775807 && sign == 1)
			return (-1);
		if (result > 9223372036854775807 && sign == -1)
			return (0);
		i++;
	}
	return (result * sign);
}

char	*join_arg(int argc, char **argv)
{
	int		i;
	int		len;
	int		k;
	char	*join_d;
	int		j;

	i = 1;
	len = 0;
	k = 0;
	while (i < argc)
	{
		len += ft_strlen(argv[i]);
		i++;
		if (i < argc)
			len++;
	}
	join_d = malloc(len + 1);
	if (!join_d)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			join_d[k++] = argv[i][j++];
		if (i < argc - 1)
			join_d[k++] = ' ';
		i++;
	}
	join_d[k] = '\0';
	return (join_d);
}

int	get_largest_index(t_stack *stack)
{
	int		largest_index;
	t_stack	*temp;

	largest_index = stack->index;
	temp = stack;
	while (temp != NULL)
	{
		if (temp->index > largest_index)
			largest_index = temp->index;
		temp = temp->next;
	}
	return (largest_index);
}

int	get_index_position(t_stack *stack, int index)
{
	int	position;

	position = 0;
	while (stack != NULL)
	{
		if (stack->index == index)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}
