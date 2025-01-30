/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoubair Kharbach <marvin@student.42.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:58:15 by Zoubair           #+#    #+#             */
/*   Updated: 2025/01/30 12:58:15 by Zoubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

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

    for (i = 1; i < argc; i++)
        len += ft_strlen(argv[i]) + 1;

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

char **ft_split(char const *s)
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

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Error: No input provided\n");
        return 1;
    }

    char *joined = join_arg(argc, argv);
    if (!joined)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    char **split = ft_split(joined);
    free(joined);

    if (!split)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Split numbers:\n");
    for (int i = 0; split[i]; i++)
        printf("%s\n", split[i]);

    free_split(split);
    return 0;
}
