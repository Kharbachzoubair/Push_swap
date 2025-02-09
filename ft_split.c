/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:41:40 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/09 12:16:31 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
char **ft_split(char *s)
{
    int i = 0, k = 0, j, words = count_words(s);
    char **result = malloc((words + 1) * sizeof(char *));
    if (!result)
        return NULL;

    while (s[i])
    {
        // Skip leading spaces
        while (s[i] == ' ')
            i++;
        
        if (!s[i])  // End of string
            break;

        // Find the end of the next word
        j = i;
        while (s[j] && s[j] != ' ')
            j++;

        // Allocate memory for the current word
        result[k] = malloc((j - i + 1) * sizeof(char));
        if (!result[k])  // Free already allocated memory if malloc fails
        {
            while (k--)
                free(result[k]);
            free(result);
            return NULL;
        }

        // Copy the word
        int m = 0;
        while (i < j)
            result[k][m++] = s[i++];
        result[k][m] = '\0';  // Null-terminate the word
        k++;
    }
    result[k] = NULL;  // Null-terminate the array of strings
    return result;
}
void free_split(char **split)
{
    int i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}