/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:15:32 by zkharbac          #+#    #+#             */
/*   Updated: 2025/04/03 11:14:57 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort3(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > c && c > b)
		ra(stack);
	else if (b > a && a > c)
		rra(stack);
	else if (b > c && c > a)
	{
		sa(stack);
		ra(stack);
	}
	else if (c > a && a > b)
		sa(stack);
}

void	sort4(t_stack **stack_a, t_stack **stack_b)
{
	int	min_val;

	min_val = find_min(*stack_a);
	move_to_top(stack_a, min_val);
	pb(stack_a, stack_b);
	sort3(stack_a);
	pa(stack_a, stack_b);
}

void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	int	min_val;
	int	max_val;

	min_val = find_min(*stack_a);
	move_to_top(stack_a, min_val);
	pb(stack_a, stack_b);
	max_val = find_max(*stack_a);
	move_to_top(stack_a, max_val);
	pb(stack_a, stack_b);
	sort3(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	pa(stack_a, stack_b);
}
