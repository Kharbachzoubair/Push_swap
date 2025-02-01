/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:41:40 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/01 11:56:23 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **ft_split(char  *s)
{
    int i = 0, k = 0, j, words = count_words((char *)s);
    char **result = malloc((words + 1) * sizeof(char *));
    if (!result)
        return NULL;

    while (s[i])
    {
        while (s[i] == ' ')
            i++;
        if (!s[i])
            break;

        j = i;
        while (s[j] && s[j] != ' ')
            j++;

        result[k] = malloc((j - i + 1) * sizeof(char));
        if (!result[k])
            return NULL;

        int m = 0;
        while (i < j)
            result[k][m++] = s[i++];
        result[k][m] = '\0';
        k++;
    }
    result[k] = NULL;
    return result;
}

void free_split(char **split)
{
    for (int i = 0; split[i]; i++)
        free(split[i]);
    free(split);
}
