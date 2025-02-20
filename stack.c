/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:21:33 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/09 15:10:40 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_node(int value)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (!node)
        return NULL;
    node->value = value;
    node->index = -1;  // Initialize index
    node->next = NULL;
    return node;
}

t_stack *build_stack(char **numbers)
{
    t_stack *head = NULL;
    t_stack *tail = NULL;
    int i = 0;

    while (numbers[i])
    {
        int num = ft_atoi(numbers[i]);
        t_stack *new_node = create_node(num);

        if (!new_node)
        {
            free_stack(head);
            return NULL;
        }

        if (!head)
            head = new_node;
        else
            tail->next = new_node;

        tail = new_node;
        i++;
    }

    index_stack(head);  // Assign indexes after building the stack
    return head;
}

void index_stack(t_stack *stack)
{
    t_stack *current;
    t_stack *smallest;
    int index = 0;
    int size = stack_size(stack);

    while (index < size)
    {
        smallest = NULL;
        current = stack;

        while (current)
        {
            if (current->index == -1) // Only process unindexed numbers
            {
                if (!smallest || current->value < smallest->value)
                    smallest = current;
            }
            current = current->next;
        }

        if (smallest)
            smallest->index = index++; // Assign index
    }
}

void print_stack(t_stack *stack)
{
    t_stack *current = stack;
    while (current)
    {
        printf("Value: %d | Index: %d\n", current->value, current->index);
        current = current->next;
    }
}

void free_stack(t_stack *stack)
{
    t_stack *tmp;
    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

int stack_size(t_stack *stack)
{
    int count = 0;
    while (stack)
    {
        stack = stack->next;
        count++;
    }
    return count;
}
int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
