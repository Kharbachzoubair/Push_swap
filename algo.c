/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:30:51 by marvin            #+#    #+#             */
/*   Updated: 2025/03/23 21:20:05 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rangeof(int len)
{
	if (len < 20)
		return (3);
	return (len / 20 + 10);
}

int	find_max_index(t_stack *stack)
{
	int	max_index;

	max_index = -1;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}

int	find_max_index_position(t_stack *stack)
{
	int	max_pos;
	int	position;
	int	max_index;

	max_pos = 0;
	position = 0;
	max_index = find_max_index(stack);
	while (stack)
	{
		if (stack->index == max_index)
			return (position);
		position++;
		stack = stack->next;
	}
	return (max_pos);
}

void	range_algo(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	range;
	int	index;

	i = 0;
	range = rangeof(stack_size(*stack_a));
	while (*stack_a)
	{
		index = (*stack_a)->index;
		if (index < i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if (index >= i && index < range + i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	move_largest_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size_stack;
	int	largest_index;
	int	largest_index_pos;

	while (*stack_b)
	{
		size_stack = stack_size(*stack_b);
		largest_index = find_max_index(*stack_b);
		largest_index_pos = find_max_index_position(*stack_b);
		if (largest_index_pos <= size_stack / 2)
		{
			while ((*stack_b)->index != largest_index)
				rb(stack_b);
		}
		else
		{
			while ((*stack_b)->index != largest_index)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	larger_sort(t_stack **stack_a, t_stack **stack_b)
{
	range_algo(stack_a, stack_b);
	move_largest_to_a(stack_a, stack_b);
}
