/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:53:45 by zkharbac          #+#    #+#             */
/*   Updated: 2025/03/28 20:20:07 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_stat
{
	int	i;
	int	sign;
}	t_stat;

int	ft_atoi_helper(char *str, int i, int sign, unsigned long long result)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647 && sign == 1)
			return (-1);
		if (result > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (result * sign);
}

int	ft_atoi(char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (ft_atoi_helper(str, i, sign, result));
}

int	ft_atoi_helper2(char *str, t_stat info, unsigned long long result,
	int *error)
{
	while (str[info.i])
	{
		if (str[info.i] >= '0' && str[info.i] <= '9')
		{
			result = result * 10 + (str[info.i] - '0');
			if (result > 2147483647 && info.sign == 1)
			{
				*error = 1;
				return (-1);
			}
			if (result > 2147483648 && info.sign == -1)
			{
				*error = 1;
				return (0);
			}
			info.i++;
		}
	}
	return (result * info.sign);
}

int	ft_atoi2(char *str, int *error)
{
	int					i;
	int					sign;
	unsigned long long	result;
	t_stat				info;

	i = 0;
	result = 0;
	sign = 1;
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == 0)
		return (-1);
	info.i = i;
	info.sign = sign;
	return (ft_atoi_helper2(str, info, result, error));
}
