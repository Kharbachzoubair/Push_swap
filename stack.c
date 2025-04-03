/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:21:33 by zkharbac          #+#    #+#             */
/*   Updated: 2025/03/27 14:31:15 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *stack)
{
	int	index;
	int	size;

	index = 0;
	size = stack_size(stack);
	while (index < size)
	{
		assign_index_to_smallest(stack, &index);
	}
}

t_stack	*initialize_stack(int argc, char **argv)
{
	char	*joined;
	char	**numbers;
	t_stack	*stack;

	joined = join_arg(argc, argv);
	if (!joined)
		return (NULL);
	numbers = ft_split(joined);
	free(joined);
	if (!numbers || !validate_numbers(numbers))
	{
		free_split(numbers);
		return (NULL);
	}
	stack = build_stack(numbers);
	free_split(numbers);
	return (stack);
}
