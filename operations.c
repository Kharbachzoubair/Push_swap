/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:57:36 by marvin            #+#    #+#             */
/*   Updated: 2025/03/23 21:48:16 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

int	move_count = 0;

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = (*stack);
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	move_count++;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!(*from))
		return ;
	tmp = (*from);
	(*from) = (*from)->next;
	tmp->next = (*to);
	(*to) = tmp;
	move_count++;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = NULL;
	last = (*stack);
	while (last->next)
		last = last->next;
	last->next = tmp;
	move_count++;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!(*stack) || !((*stack)->next))
		return ;
	prev = NULL;
	last = (*stack);
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (!prev)
		return ;
	prev->next = NULL;
	last->next = (*stack);
	(*stack) = last;
	move_count++;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
