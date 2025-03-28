/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:30:51 by marvin            #+#    #+#             */
/*   Updated: 2025/03/28 23:30:24 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

void	range_algo(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	range;
	int	index;
	int	size;

	i = 0;
	range = rangeof(stack_size(*stack_a));
	size = stack_size(*stack_a);
	while (*stack_a)
	{
		index = (*stack_a)->index;
		if (index <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if (index <= i + range)
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
