/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:41:55 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/01 12:15:48 by zkharbac         ###   ########.fr       */
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

// Function prototypes for utility functions
int     ft_strlen(char *s);
int     count_words(char *s);
char   *join_arg(int argc, char **argv);
int     validate_numbers(char **numbers);
char  **ft_split(char const *s);
void    free_split(char **split);

// Prototypes for functions used in validation
int     is_valid_number(char *str);
int     is_within_int_range(char *str);
int     has_duplicates(char **numbers);

// Custom conversion functions
long    ft_atol(char *str);
int     ft_atoi(char *str);

#endif
