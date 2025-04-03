/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_index_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:29:04 by zkharbac          #+#    #+#             */
/*   Updated: 2025/04/03 11:14:19 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
