/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:30:51 by marvin            #+#    #+#             */
/*   Updated: 2025/02/11 16:31:32 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int determine_chunk_size(int size)
{
    if (size <= 100)
        return 20;
    else if (size <= 500)
        return 47; // Smaller chunk size for better move distribution
    return 50; // Default chunk size for larger stacks
}


int find_closest_in_range(t_stack *stack, int start_range, int end_range)
{
    int top_moves = 0;
    int bottom_moves = 0;
    int size = stack_size(stack);
    t_stack *current = stack;

    while (current)
    {
        if (current->index >= start_range && current->index <= end_range)
            break;
        current = current->next;
        top_moves++;
    }

    bottom_moves = size - top_moves;
    return (top_moves <= bottom_moves) ? 1 : -1;
}

int find_max_index_position(t_stack *stack)
{
    int pos = 0;
    int max_pos = 0;
    int max_value = stack->index;
    t_stack *current = stack;

    while (current)
    {
        if (current->index > max_value)
        {
            max_value = current->index;
            max_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return max_pos;
}

void range_sort(t_stack **stack_a, t_stack **stack_b)
{
    int size = stack_size(*stack_a);
    int chunk_size = determine_chunk_size(size);
    int start_range = 0;
    int end_range = chunk_size - 1;
    int total_pushed = 0;

    // Instead of blindly iterating, let's try smaller ranges
    while (total_pushed < size)
    {
        int i = 0;
        int current_size = stack_size(*stack_a);
        int found = 0;

        while (i < current_size)
        {
            int direction = find_closest_in_range(*stack_a, start_range, end_range);

            if ((*stack_a)->index >= start_range && (*stack_a)->index <= end_range)
            {
                pb(stack_a, stack_b);
                total_pushed++;

                // Add some extra checks to minimize unnecessary rotations
                if (*stack_b && (*stack_b)->index > start_range + (chunk_size / 2))
                    rb(stack_b);
                found = 1;
            }
            else
            {
                // Rotate only if the element is not in range
                if (direction == 1)
                    ra(stack_a);
                else
                    rra(stack_a);
            }
            i++;
        }

        // If no elements were found in the current range, break out early
        if (!found)
            break;

        // Increase the range to sort the next chunk
        start_range += chunk_size;
        end_range += chunk_size;
    }

    // Optimize sorting of stack B
    sort_stack_b(stack_a, stack_b);
}

void sort_stack_b(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_b)
    {
        int size = stack_size(*stack_b);
        int max_pos = find_max_index_position(*stack_b);

        // Move elements to stack A with minimal rotations
        if (max_pos > size / 2)
        {
            while (max_pos++ < size)
                rrb(stack_b);
        }
        else
        {
            while (max_pos-- > 0)
                rb(stack_b);
        }

        // Push back to stack A
        pa(stack_a, stack_b);
    }
}
