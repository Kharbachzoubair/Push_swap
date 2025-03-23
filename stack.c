/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:21:33 by zkharbac          #+#    #+#             */
/*   Updated: 2025/03/07 17:30:23 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	ft_putnbr(int n)
{
	char		c;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

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
	int		num;
	t_stack	*new_node;

	head = NULL;
	tail = NULL;
	i = 0;
	while (numbers[i])
	{
		num = ft_atoi(numbers[i]);
		new_node = create_node(num);
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

void	index_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*smallest;
	int		index;
	int		size;

	index = 0;
	size = stack_size(stack);
	while (index < size)
	{
		smallest = NULL;
		current = stack;
		while (current)
		{
			if (current->index == -1)
			{
				if (!smallest || current->value < smallest->value)
					smallest = current;
			}
			current = current->next;
		}
		if (smallest)
			smallest->index = index++;
	}
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

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
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
