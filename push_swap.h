/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:41:55 by zkharbac          #+#    #+#             */
/*   Updated: 2025/02/01 11:56:13 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

int ft_strlen(char *s);
int count_words(char *s);
char *join_arg(int argc, char **argv);
int validate_numbers(char **numbers);
char **ft_split(char *s);
int is_within_int_range(char *str);
int has_duplicates(char **numbers);
int ifnumber(char *s);
#endif