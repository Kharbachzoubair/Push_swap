/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:30:51 by zkharbac          #+#    #+#             */
/*   Updated: 2025/01/27 13:26:17 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the linked list structure
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

// Function to create a new node
t_node *create_node(int value) {
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return NULL;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the end of the list
void add_node(t_node **head, int value) {
    t_node *new_node = create_node(value);
    if (!new_node) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    if (!*head) {
        *head = new_node;
    } else {
        t_node *temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
}

// Function to print the linked list
void print_list(t_node *head) {
    t_node *temp = head;
    while (temp) {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

// Function to free the linked list
void free_list(t_node *head) {
    t_node *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to check if a string is a valid number
int is_valid_number(char *str) {
    if (*str == '+' || *str == '-')
        str++;
    if (!*str) // If there's no digit after + or -
        return 0;
    while (*str) {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

// Custom atoi function
int ft_atoi(char *str) {
    int sign = 1;
    int result = 0;

    if (*str == '+' || *str == '-') {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str && isdigit(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result * sign;
}

// Custom split function
char **ft_split(char const *s, char c) {
    char **result;
    int i = 0, j, k, word_count = 0;

    if (!s)
        return NULL;

    // Count words
    for (i = 0; s[i]; i++)
        if ((i == 0 || s[i - 1] == c) && s[i] != c)
            word_count++;

    // Allocate memory for the result
    result = (char **)malloc((word_count + 1) * sizeof(char *));
    if (!result)
        return NULL;

    // Split the string
    i = 0, k = 0;
    while (s[i]) {
        while (s[i] == c)
            i++;
        if (s[i]) {
            j = i;
            while (s[j] && s[j] != c)
                j++;
            result[k] = (char *)malloc(j - i + 1);
            if (!result[k])
                return NULL;
            for (int x = 0; x < j - i; x++)
                result[k][x] = s[i + x];
            result[k][j - i] = '\0';
            k++;
            i = j;
        }
    }
    result[k] = NULL;
    return result;
}

// Function to parse arguments
void parse_arguments(char *arg, t_node **list) {
    char **numbers = ft_split(arg, ' ');
    int i = 0;

    if (!numbers) {
        printf("Error: Memory allocation failed during split.\n");
        exit(1);
    }

    while (numbers[i]) {
        if (!is_valid_number(numbers[i])) {
            printf("Error: Invalid argument '%s'\n", numbers[i]);
            free_list(*list);
            exit(1);
        }
        add_node(list, ft_atoi(numbers[i]));
        free(numbers[i]);
        i++;
    }
    free(numbers);
}

// Main function
int main(int argc, char **argv) {
    t_node *list = NULL;

    if (argc < 2) {
        printf("Error: No arguments provided.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        parse_arguments(argv[i], &list);
    }

    print_list(list);
    free_list(list);
    return 0;
}

