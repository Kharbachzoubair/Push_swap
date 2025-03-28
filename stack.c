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
