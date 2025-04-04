/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:15:32 by zkharbac          #+#    #+#             */
/*   Updated: 2025/04/03 11:14:24 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(t_stack **stack, int value)
{
	t_stack	*temp;
	int		count;

	temp = *stack;
	count = 0;
	while (temp)
	{
		if (temp->value == value)
			break ;
		count++;
		temp = temp->next;
	}
	if (count == 0)
		return ;
	if (count <= stack_size(*stack) / 2)
	{
		while ((*stack)->value != value)
			ra(stack);
	}
	else
	{
		while ((*stack)->value != value)
			rra(stack);
	}
}
