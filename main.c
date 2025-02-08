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

    t_stack *stack_a = build_stack(numbers);
    t_stack *stack_b = NULL;
    free_split(numbers);
    
    if (!stack_a)
    {
        printf("Error building stack\n");
        return 1;
    }

    printf("\nStack A before sorting:\n");
    print_stack(stack_a);

    // Step 1: Index the stack
    index_stack(stack_a);

    // Step 2: Get size and determine sorting method
    int size = stack_size(stack_a);

    if (size == 2)
        sa(&stack_a);
    else if (size == 3)
        sort3(&stack_a);
    else if (size == 4)
        sort4(&stack_a, &stack_b);
    else if (size == 5)
        sort5(&stack_a, &stack_b);
    else if (size > 5)
         range_sort(&stack_a, &stack_b);
        sort_stack_b(&stack_a, &stack_b); 

    printf("\nStack A after sorting:\n");
    print_stack(stack_a);
    
    free_stack(stack_a);
    
    return 0;
}
