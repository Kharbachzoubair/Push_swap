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

#include "push_swap.h"

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

    if (!validate_numbers(split))
    {
        free_split(split);
        return 1;
    }

    printf("Valid numbers:\n");
    for (int i = 0; split[i]; i++)
        printf("%s\n", split[i]);

    free_split(split);
    return 0;
}
