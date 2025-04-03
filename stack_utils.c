/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:14:00 by zkharbac          #+#    #+#             */
/*   Updated: 2025/04/03 11:15:13 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

t_stack	*build_stack(char **numbers)
{
	t_stack	*head;
	t_stack	*tail;
	int		i;
	t_stack	*new_node;

	head = NULL;
	tail = NULL;
	i = 0;
	while (numbers[i])
	{
		new_node = create_node_from_string(numbers[i]);
		if (!new_node)
		{
			free_stack(head);
			return (NULL);
		}
		if (!head)
			head = new_node;
		else
			tail->next = new_node;
		tail = new_node;
		i++;
	}
	index_stack(head);
	return (head);
}

t_stack	*create_node_from_string(char *str)
{
	int		num;

	num = ft_atoi(str);
	return (create_node(num));
}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		ft_putnbr(current->value);
		write(1, " | ", 3);
		ft_putnbr(current->index);
		write(1, "\n", 1);
		current = current->next;
	}
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
