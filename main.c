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


#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

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
int validate_numbers(char **numbers)
{
    int i = 0;

    while (numbers[i])
    {
        if (!is_valid_number(numbers[i]) || !is_within_int_range(numbers[i]))
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

int is_within_int_range(char *str)
{
    long num = ft_atol(str);  // Convert to long

    if (num < INT_MIN || num > INT_MAX)
        return (0);
    return (1);
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

int ifnumber(char *s)
{
    int i;

    i = 0;
    if(!s[i] || !s[0])
        return 0;
    if((s[i]=='-' || s[i]=='+') && s[i+1])
        i++;
    while(s[i])
        if(s[i]<'0' && s[i]>'9')
            return 0;
        i++;  
    return 1;
}
int main(int argc , char **argv)
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
  
