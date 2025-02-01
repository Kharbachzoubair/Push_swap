/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:53:45 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/01 11:56:18 by zkharbac         ###   ########.fr       */
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

char *join_arg(int argc, char **argv)
{
    int i = 1, j, k = 0, len = 0;
    char *join_d;

    while(i < argc)
    {
        len+=ft_strlen(argv[i] + 1);
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