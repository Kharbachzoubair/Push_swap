/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:30:51 by marvin            #+#    #+#             */
/*   Updated: 2025/02/08 01:30:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int determine_chunk_size(int size)
{
    if (size <= 100)
        return 15;
    else
        return 30;
}

// Push elements from stack_a to stack_b in chunks
void range_sort(t_stack **stack_a, t_stack **stack_b)
{
    int size = stack_size(*stack_a);
    int chunk_size = determine_chunk_size(size);
    int start_range = 0;
    int end_range = chunk_size - 1;

    while (*stack_a)
    {
        if ((*stack_a)->index >= start_range && (*stack_a)->index <= end_range)
        {
            pb(stack_a, stack_b);
            if ((*stack_b)->index <= start_range + (chunk_size / 2))
                rb(stack_b);
            start_range++;
            end_range++;
        }
        else
        {
            ra(stack_a);
        }
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
