/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:04:42 by zkharbac          #+#    #+#             */
/*   Updated: 2025/03/28 20:22:33 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_within_int_range(char *str)
{
	int	num;
	int	error;

	error = 0;
	num = ft_atoi2(str, &error);
	if (num == -1 || error)
		return (0);
	return (1);
}

int	ifnumber(char *s)
{
	int		i;
	int		sign_count;

	i = 0;
	sign_count = 0;
	if (!s[i])
		return (0);
	if (s[i] == '-' || s[i] == '+')
	{
		sign_count++;
		i++;
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (sign_count <= 1);
}

int	has_duplicates(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_atoi(numbers[i]) == ft_atoi(numbers[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_numbers(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (!ifnumber(numbers[i]) || !is_within_int_range(numbers[i]))
			return (0);
		i++;
	}
	if (has_duplicates(numbers))
		return (0);
	return (1);
}
