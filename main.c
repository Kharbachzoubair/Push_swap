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


/* ===================== */
/*         MAIN         */
/* ===================== */
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
    
    char **numbers = ft_split(joined);
    free(joined);
    
    if (!numbers)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    if (!validate_numbers(numbers))
    {
        free_split(numbers);
        return 1;
    }
    
    printf("Valid numbers:\n");
    
    int i = 0;
    while (numbers[i])
    {
        printf("%d\n", ft_atoi(numbers[i])); 
        i++;
    }
    
    free_split(numbers);
    return 0;
}
