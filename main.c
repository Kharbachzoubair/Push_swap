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

// Function to calculate the size of the stack


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
    free_split(numbers);
    if (!stack_a)
    {
        printf("Error building stack\n");
        return 1;
    }
    
    printf("\nStack A before sorting:\n");
    print_stack(stack_a);

    // Get the size of the stack and perform sorting accordingly
    int size = stack_size(stack_a);
    
    if (size == 2)
        swap(&stack_a);  // Swap for stack size 2
    else if (size == 3)
        sort3(&stack_a);  // Sort for stack size 3
    else if (size > 3)
    {
        // Implement logic for sorting larger stacks (this is your job to define the sorting algorithm)
        printf("Sorting logic for larger stacks should be implemented here.\n");
    }

    printf("\nStack A after sorting:\n");
    print_stack(stack_a);
    free_stack(stack_a);
    
    return 0;
}

