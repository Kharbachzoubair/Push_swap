/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:30:51 by marvin            #+#    #+#             */
/*   Updated: 2025/02/11 17:15:11 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"  // Assuming these functions are defined in libft.h

// Function to determine the range based on the stack length
int rangeof(int len)
{
    if (len < 20)
        return 3;  // Small stacks use a small range
    return (len / 20 + 10);  // Larger stacks use a larger range
}

// Main sorting algorithm to push elements to stack_b in ranges
void range_algo(t_stack **stack_a, t_stack **stack_b)
{
    int i = 0;
    int range;
    int index;

    if (*stack_a == NULL || *stack_b == NULL)
        return;

    range = rangeof(stack_size(*stack_a));  // Get the dynamic range based on stack size
    while (*stack_a != NULL)
    {
        index = (*stack_a)->index;
        if (index < i)  // If index is smaller than i, push to stack_b
        {
            pa(stack_a, stack_b);  // Call pa function
            rb(stack_b);  // Call rb function
            i++;
        }
        else if (index >= i && index < range + i)  // If within the range, push to stack_b
        {
            pa(stack_a, stack_b);  // Call pa function
            i++;
        }
        else  // Otherwise, rotate stack_a
            ra(stack_a);  // Call ra function
    }
}

// Function to move the largest element from stack_b to stack_a
void move_largest_to_a(t_stack **stack_a, t_stack **stack_b)
{
    int size_stack;
    int largest_index;
    int largest_index_pos;

    while (*stack_b != NULL)
    {
        size_stack = stack_size(*stack_b);
        largest_index = get_largest_index(*stack_b);
        largest_index_pos = get_index_position(*stack_b, largest_index);

        if (largest_index_pos <= size_stack / 2)  // If the largest element is in the top half of stack_b
        {
            while ((*stack_b)->index != largest_index)
                rb(stack_b);  // Call rb function
        }
        else  // Otherwise, reverse rotate stack_b
        {
            while ((*stack_b)->index != largest_index)
                rrb(stack_b);  // Call rrb function
        }
        pa(stack_a, stack_b);  // Push the largest element to stack_a
    }
}

// Check if the stack is sorted in ascending order
int is_sorted(t_stack *stack)
{
    while (stack->next)
    {
        if (stack->value > stack->next->value)  // If an element is greater than the next one, stack is not sorted
            return 0;
        stack = stack->next;
    }
    return 1;  // Stack is sorted
}
