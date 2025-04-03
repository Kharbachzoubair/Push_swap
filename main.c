/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 03:21:27 by marvin            #+#    #+#             */
/*   Updated: 2025/04/01 15:03:30 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_error(void)
{
	write(2, "Error\n", 6);
}

int	is_empty_or_spaces(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	check_args(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (is_empty_or_spaces(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort3(stack_a);
	else if (size == 4)
		sort4(stack_a, stack_b);
	else if (size == 5)
		sort5(stack_a, stack_b);
	else
		larger_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (!check_args(argc, argv))
	{
		handle_error();
		return (1);
	}
	stack_a = initialize_stack(argc, argv);
	if (!stack_a)
	{
		handle_error();
		return (1);
	}
	stack_b = NULL;
	size = stack_size(stack_a);
	if (size > 1 && !is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b, size);
	free_stack(stack_a);
	return (0);
}
