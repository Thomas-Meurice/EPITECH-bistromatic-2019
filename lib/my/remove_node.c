/*
** EPITECH PROJECT, 2024
** CPool_Day3
** File description:
** Created by thomas.meurice@epitech.eu,
*/

#include "my.h"
#include <nb_list.h>
#include <stdlib.h>

void remove_node(nb_list_t *head)
{
    nb_list_t *tmp = head->next;

    if (head->next != NULL && head->next->next != NULL) {
        head->next = head->next->next;
        head->next->prev = head;
    } else {
        head->next = NULL;
    }
    free(tmp);
}