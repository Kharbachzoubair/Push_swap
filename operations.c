/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:57:36 by marvin            #+#    #+#             */
/*   Updated: 2025/02/05 22:57:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **stack)
{
    if(!*stack || !(*stack)->next )
        return;
    
    t_stack *first=(*stack);
    t_stack *second=(*stack)->next;
     first->next=second->next;
     second=first->next;
     *stack=second;


}

void push(t_stack **from,t_stack **to)
{
    if(!(*from))
        return;
    t_stack *tmp=(*from);
    (*from)=(*from)->next;
    tmp->next=(*to);
    (*to)=tmp;
    
    
}
void rotate(t_stack **stack)
{
    if(!(*stack) || !((*stack)->next))
        return;
    t_stack *tmp=(*stack);
    (*stack)=(*stack)->next;
    t_stack *last=(*stack);
    while(last->next)
    {
        printf("%d",last->value);
        last=last->next;
    }
    last->next=tmp;
    tmp->next=NULL;

}

void reverse_rotate(t_stack **stack)
{
    if(!(*stack)|| !((*stack)->next))
        return;
    t_stack *prev=(*stack);
    (*stack)=(*stack)->next;
    t_stack *last=(*stack);
    while(last->next)
        last=last->next;
    
    last->next=prev;
    prev->next=NULL;
}