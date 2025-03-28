/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:41:58 by zkharbac          #+#    #+#             */
/*   Updated: 2025/03/28 14:22:45 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	assign_index_to_smallest(t_stack *stack, int *index)
{
	t_stack	*current;
	t_stack	*smallest;

	smallest = NULL;
	current = stack;
	while (current)
	{
		if (current->index == -1)
		{
			if (!smallest || current->value < smallest->value)
				smallest = current;
		}
		current = current->next;
	}
	if (smallest)
		smallest->index = (*index)++;
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
