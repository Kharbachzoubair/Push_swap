/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:41:55 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/02 16:49:20 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  

// Structure declaration
typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;


int     ft_strlen(char *s);
int     count_words(char *s);
char   *join_arg(int argc, char **argv);
int     validate_numbers(char **numbers);
char  **ft_split(char  *s);
void    free_split(char **split);

int     is_valid_number(char *str);
int     is_within_int_range(char *str);
int     has_duplicates(char **numbers);
int     ifnumber(char *s);

int     ft_atoi( char *str);
t_stack *create_node(int value);
t_stack *build_stack(char **numbers);
void print_stack(t_stack *stack);
void free_stack(t_stack *stack);

#endif
