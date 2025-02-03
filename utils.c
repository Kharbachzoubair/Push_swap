/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:53:45 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/02 13:07:57 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

int count_words(char *s)
{
    int i = 0, word = 0, count = 0;
    while (s[i])
    {
        if (s[i] == ' ')
            word = 0;
        else if (word == 0)
        {
            count++;
            word = 1;
        }
        i++;
    }
    return count;
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
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > 9223372036854775807 && sign == 1)
			return (-1);
		if (result > 9223372036854775807 && sign == -1)
			return (0);
		i++;
	}
	return (result * sign);
}
char *join_arg(int argc, char **argv)
{
    int i = 1, j, k = 0, len = 0;
    char *join_d;

    
    while (i < argc)
    {
        len += ft_strlen(argv[i]);
        i++;
    }

    join_d = malloc(len + 1);
    if (!join_d)
        return NULL;

    
    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
            join_d[k++] = argv[i][j++];
        if (i < argc - 1)
            join_d[k++] = ' ';
        i++;
    }
    join_d[k] = '\0';
    return join_d;
}
