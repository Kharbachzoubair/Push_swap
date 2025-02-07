/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:15:32 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/06 16:47:03 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(t_stack *stack)
{
    int min = stack->value;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return min;
}

int find_max(t_stack *stack)
{
    int max = stack->value; // Initialize with the first value
    while (stack)
    {
        if (stack->value > max)
            max = stack->value; // Update the maximum if a larger value is found
        stack = stack->next;
    }
    return max;
}

void move_to_top(t_stack **stack, int value)
{
    t_stack *temp = *stack;
    int count = 0;
    
    // Count the number of steps to rotate the value to the top
    while (temp)
    {
        if (temp->value == value)
            break;
        count++;
        temp = temp->next;
    }
    
    // If the value is already at the top, no need to rotate
    if (count == 0)
        return;
    
    // If count is smaller than half the stack size, rotate
    if (count <= stack_size(*stack) / 2)
    {
        while ((*stack)->value != value)
            rotate(stack);
    }
    // Otherwise, reverse rotate
    else
    {
        while ((*stack)->value != value)
            reverse_rotate(stack);
    }
}


void sort_2(t_stack **stack)
{
    if ((*stack)->value > (*stack)->next->value)
        sa(stack);  // Use sa() to print "sa\n"
}

void sort3(t_stack **stack)
{
    if (!stack || !*stack || !(*stack)->next)
        return;

    int a = (*stack)->value;
    int b = (*stack)->next->value;
    int c = (*stack)->next->next->value;

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

void sort4(t_stack **stack_a, t_stack **stack_b)
{
    int min_val = find_min(*stack_a);
    move_to_top(stack_a, min_val);
    pb(stack_a, stack_b);  // Push min to stack B
    sort3(stack_a);
    pa(stack_a, stack_b);  // Push back to A
}

void sort5(t_stack **stack_a, t_stack **stack_b)
{
    int min_val = find_min(*stack_a);
    int max_val = find_max(*stack_a);
    
    move_to_top(stack_a, min_val);
    pb(stack_a, stack_b);  // Push smallest to B

    move_to_top(stack_a, max_val);
    pb(stack_a, stack_b);  // Push largest to B

    sort3(stack_a);

    pa(stack_a, stack_b);  // Push back largest
    ra(stack_a);  // Rotate to correct position

    pa(stack_a, stack_b);  // Push back smallest
}
