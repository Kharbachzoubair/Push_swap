/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:21:33 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/02 17:02:29 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_node(int value)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (!node)
        return NULL;
    node->value = value;
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
    return head;
}

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
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
