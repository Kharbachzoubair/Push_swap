/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:01:54 by zkharbac          #+#    #+#             */
/*   Updated: 2025/01/18 15:49:53 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

int main() {
     Node *head = NULL;
     Node *second = NULL;
     Node *third = NULL;

    // Allocation de mémoire pour les nœuds
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));

    // Initialisation des nœuds
    head->data = 1;        // Donnée du premier nœud
    head->next = second;   // Pointeur vers le deuxième nœud

    second->data = 2;      // Donnée du deuxième nœud
    second->next = third;  // Pointeur vers le troisième nœud

    third->data = 3;       // Donnée du troisième nœud
    third->next = NULL;    // Fin de la liste

    // Parcours et affichage des éléments
 Node *temp = head;
    printf("\n\nList elements are - \n");
    while (temp != NULL) {
        printf("%d ---> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    

    return 0;
}


