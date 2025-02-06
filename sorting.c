/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:15:32 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/06 15:23:58 by zkharbac         ###   ########.fr       */
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
