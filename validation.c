/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:04:42 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/02 12:56:30 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int validate_numbers(char **numbers)
{
    int i = 0;

    while (numbers[i])
    {
        if (!ifnumber(numbers[i]) || !is_within_int_range(numbers[i]))
        {
            write(2, "Error\n", 6);
            return (0);
        }
        i++;
    }
    if (has_duplicates(numbers))
    {
        write(2, "Error\n", 6);
        return (0);
    }
    return (1);
}
int is_within_int_range(char *str)
{
    long num = ft_atoi(str);
    if (num < INT_MIN || num > INT_MAX)
        return (0);
    return (1);
}
int ifnumber(char *s)
{
    int i = 0;
    int sign_count = 0;

    if (!s[i])
        return 0;
    if (s[i] == '-' || s[i] == '+') 
    {
        sign_count++;
        i++;
    }

    while (s[i]) {
        if (s[i] < '0' || s[i] > '9') 
            return 0;
        i++;
    }

    return sign_count <= 1; 
}

int has_duplicates(char **numbers)
{
    int i = 0, j;

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