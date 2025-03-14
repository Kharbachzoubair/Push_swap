/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:57:36 by marvin            #+#    #+#             */
/*   Updated: 2025/02/06 14:45:51 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int move_count = 0; 

void swap(t_stack **stack)
{
    if (!*stack || !(*stack)->next)
        return;

    t_stack *first = (*stack);
    t_stack *second = (*stack)->next;
    first->next = second->next;
    second->next = first;
    *stack = second;

    move_count++;
}

void sa(t_stack **stack_a)
{
    swap(stack_a);
    write(1, "sa\n", 3);
}

void sb(t_stack **stack_b)
{
    swap(stack_b);
    write(1, "sb\n", 3);
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
}

void push(t_stack **from, t_stack **to)
{
    if (!(*from))
        return;

    t_stack *tmp = (*from);
    (*from) = (*from)->next;
    tmp->next = (*to);
    (*to) = tmp;

    move_count++;
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    write(1, "pa\n", 3);
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    write(1, "pb\n", 3);
}

void rotate(t_stack **stack)
{
    if (!(*stack) || !((*stack)->next))
        return;
    
    t_stack *tmp = (*stack);
    (*stack) = (*stack)->next;
    tmp->next = NULL; // Fix: Detach the old head
    
    t_stack *last = (*stack);
    while (last->next)
        last = last->next;
    
    last->next = tmp; // Reattach old head to last

    move_count++;
}

void ra(t_stack **stack_a)
{
    rotate(stack_a);
    write(1, "ra\n", 3);
}

void rb(t_stack **stack_b)
{
    rotate(stack_b);
    write(1, "rb\n", 3);
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr\n", 3);
}

void reverse_rotate(t_stack **stack)
{
    if (!(*stack) || !((*stack)->next))
        return;
    
    t_stack *prev = NULL;
    t_stack *last = (*stack);
    
    while (last->next)
    {
        prev = last;
        last = last->next;
    }

    if (!prev) // Fix: If there's only one element, return immediately
        return;
    
    prev->next = NULL; // Disconnect last node
    last->next = (*stack); // Make last node the new head
    (*stack) = last;

    move_count++;
}

void rra(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    write(1, "rra\n", 4);
}

void rrb(t_stack **stack_b)
{
    reverse_rotate(stack_b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    write(1, "rrr\n", 4);
}
