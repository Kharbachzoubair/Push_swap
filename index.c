/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:26:19 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/07 16:33:13 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void index(t_stack **a)
{
    
t_stack *tmp = *head;
t_stack *current = *head->next;

while(tmp)
{
    int count = 0;
    while (current)
    {
        if (current->data < current->next->data)
            count++;
        current = current->next;
    } 
    currnt->index = count;
    tmp = tmp->next;
}
}

4       3
-3      
-1      
6          
2       