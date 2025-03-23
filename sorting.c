/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:15:32 by zkharbac          #+#    #+#             */
/*   Updated: 2025/03/23 23:48:28 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

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
			rotate(stack);
	}
	else
	{
		while ((*stack)->value != value)
			reverse_rotate(stack);
	}
}

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

	if (!stack || !*stack || !(*stack)->next)
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
	max_val = find_max(*stack_a);
	move_to_top(stack_a, min_val);
	pb(stack_a, stack_b);
	move_to_top(stack_a, max_val);
	pb(stack_a, stack_b);
	sort3(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	pa(stack_a, stack_b);
}
