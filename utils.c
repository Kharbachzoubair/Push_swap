/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:53:45 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/09 12:15:00 by zkharbac         ###   ########.fr       */
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
    int i = 1, len = 0, k = 0;
    char *join_d;
    int j;
    // Calculate the total length, including spaces between words
    while (i < argc)
    {
        len += ft_strlen(argv[i]);
        i++;
        if (i < argc) // Add space for each space between arguments
            len++;
    }

    // Allocate memory for the combined string (including null terminator)
    join_d = malloc(len + 1);
    if (!join_d)
        return NULL;

    i = 1;
    while (i < argc)
    {
        // Copy each argument to the joined string
        j = 0;
        while (argv[i][j])
            join_d[k++] = argv[i][j++];

        // Add space between arguments, but not after the last one
        if (i < argc - 1)
            join_d[k++] = ' ';
        
        i++;
    }
    join_d[k] = '\0';  // Null-terminate the string
    return join_d;
}
