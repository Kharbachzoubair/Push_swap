/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:41:55 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/06 15:35:08 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

int     ft_strlen(char *s);
int     count_words(char *s);
char   *join_arg(int argc, char **argv);
int     validate_numbers(char **numbers);
char  **ft_split(char *s);
void    free_split(char **split);

int     is_valid_number(char *str);
int     is_within_int_range(char *str);
int     has_duplicates(char **numbers);
int     ifnumber(char *s);

int     ft_atoi(char *str);
t_stack *create_node(int value);
t_stack *build_stack(char **numbers);
void    print_stack(t_stack *stack);
void    free_stack(t_stack *stack);

void    swap(t_stack **stack);
void    push(t_stack **from, t_stack **to);
void    rotate(t_stack **stack);
void    reverse_rotate(t_stack **stack);

void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);
void    pa(t_stack **stack_a, t_stack **stack_b);
void    pb(t_stack **stack_a, t_stack **stack_b);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);

/* Sorting functions */
void    sort3(t_stack **stack);
void    sort_small_stack(t_stack **stack);
int stack_size(t_stack *stack);
void sort5(t_stack **stack);
void push_swap(t_stack **stack);


#endif
