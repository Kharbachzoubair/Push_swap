/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:15:32 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/06 16:47:03 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_2(t_stack **stack)
{
    if((*stack)->value > (*stack)->next->value)
        swap(stack);
}
void sort3(t_stack **stack)
{
    printf("\n[sort3] Stack before sorting:\n");
    print_stack(*stack);

    if (!stack || !*stack || !(*stack)->next)
        return;

    int a = (*stack)->value;
    int b = (*stack)->next->value;
    int c = (*stack)->next->next->value;

    printf("Values: a = %d, b = %d, c = %d\n", a, b, c);

    if (a > b && b > c)
    {
        swap(stack);
        reverse_rotate(stack);
    }
    else if (a > c && c > b)
        rotate(stack);
    else if (b > a && a > c)
        reverse_rotate(stack);
    else if (b > c && c > a)
    {
        swap(stack);
        rotate(stack);
    }
    else if (c > a && a > b)
        swap(stack);

    printf("\n[sort3] Stack after sorting:\n");
    print_stack(*stack);
}
int find_min(t_stack *stack)
{
    int min = stack->value; // Initialize with the first value
    while (stack)
    {
        if (stack->value < min)
            min = stack->value; // Update the minimum if a smaller value is found
        stack = stack->next;
    }
    return min;
}

int find_max(t_stack *stack)
{
    int max = stack->value; // Initialize with the first value
    while (stack)
    {
        if (stack->value > max)
            max = stack->value; // Update the maximum if a larger value is found
        stack = stack->next;
    }
    return max;
}

void move_to_top(t_stack **stack, int value)
{
    t_stack *temp = *stack;
    int count = 0;
    
    // Count the number of steps to rotate the value to the top
    while (temp)
    {
        if (temp->value == value)
            break;
        count++;
        temp = temp->next;
    }
    
    // If the value is already at the top, no need to rotate
    if (count == 0)
        return;
    
    // If count is smaller than half the stack size, rotate
    if (count <= stack_size(*stack) / 2)
    {
        while ((*stack)->value != value)
            rotate(stack);
    }
    // Otherwise, reverse rotate
    else
    {
        while ((*stack)->value != value)
            reverse_rotate(stack);
    }
}
void sort5(t_stack **stack_a, t_stack **stack_b)
{
    // Step 1: Identify the smallest and largest values
    int size = stack_size(*stack_a);
    if (size <= 3) // If it's already 3 or less, just sort3
    {
        sort3(stack_a);
        return;
    }
    
    // Find the smallest value in stack_a
    int min_val = find_min(*stack_a);
    int max_val = find_max(*stack_a);

    // Step 2: Move the smallest element to the top
    move_to_top(stack_a, min_val);
    // Step 3: Push the smallest value to stack B
    push(stack_a, stack_b);

    // Step 4: Move the largest element to the top
    move_to_top(stack_a, max_val);
    // Step 5: Push the largest value to stack B
    push(stack_a, stack_b);

    // Step 6: Sort the remaining 3 elements on stack A
    sort3(stack_a);

    // Step 7: Push the largest element back to stack A
    push(stack_b, stack_a);
    // Step 8: Push the smallest element back to stack A
    push(stack_b, stack_a);
}

