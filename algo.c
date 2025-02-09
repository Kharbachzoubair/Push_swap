/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:30:51 by marvin            #+#    #+#             */
/*   Updated: 2025/02/09 16:27:36 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int determine_chunk_size(int size)
{
    if (size <= 100)
        return 20;
    else
        return 51;
}
void range_sort(t_stack **stack_a, t_stack **stack_b)
{
    int size = stack_size(*stack_a);
    int chunk_size = determine_chunk_size(size);
    int start_range = 0;
    int end_range = chunk_size - 1;
    int total_pushed = 0;

    while (total_pushed < size) // Ensure all elements are pushed
    {
        int current_size = stack_size(*stack_a); // Update size dynamically
        int found = 0;
        
        for (int i = 0; i < current_size; i++)
        {
            if ((*stack_a)->index >= start_range && (*stack_a)->index <= end_range)
            {
                pb(stack_a, stack_b);
                total_pushed++;

                // Rotate stack_b based on the element's position
                if (*stack_b && (*stack_b)->index <= start_range + (chunk_size / 2))
                    rb(stack_b);

                found = 1;
            }
            else
            {
                ra(stack_a);
            }
        }

        // If no elements were pushed, break the loop
        if (!found) 
            break;

        start_range += chunk_size;
        end_range += chunk_size;
    }
}





// Find the position of the max index in stack_b
int find_max_index_position(t_stack *stack)
{
    int max_index = -1;
    int position = 0;
    int max_pos = 0;
    t_stack *current = stack;

    while (current)
    {
        if (current->index > max_index)
        {
            max_index = current->index;
            max_pos = position;
        }
        position++;
        current = current->next;
    }
    return max_pos;
}

// Push back sorted elements from stack_b to stack_a
void sort_stack_b(t_stack **stack_a, t_stack **stack_b)
{
    int size;
    int max_pos;

    while (*stack_b)
    {
        size = stack_size(*stack_b);
        max_pos = find_max_index_position(*stack_b);

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
        pa(stack_a, stack_b);
    }
}