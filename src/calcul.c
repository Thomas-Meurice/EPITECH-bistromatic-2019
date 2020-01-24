/*
** EPITECH PROJECT, 2019
** operator
** File description:
** operator
*/

#include "my.h"
#include "nb_list.h"
#include "ope_list.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void calculmod(nb_list_t **head, ope_list_t **head2)
{
    if ((*head)->next != NULL)
        (*head)->nb = (*head)->nb % (*head)->next->nb;
    remove_node(*head);
    if ((*head2)->next != NULL) {
        (*head2)->ope = (*head2)->next->ope;
        (*head2)->priority = (*head2)->next->priority;
        remove_node2(*head2);
    }
}

void calculdiv(nb_list_t **head, ope_list_t **head2)
{
    if ((*head)->next != NULL)
        (*head)->nb = (*head)->nb / (*head)->next->nb;
    remove_node(*head);
    if ((*head2)->next != NULL) {
        (*head2)->ope = (*head2)->next->ope;
        (*head2)->priority = (*head2)->next->priority;
        remove_node2(*head2);
    }
}

void calculsub(nb_list_t **head, ope_list_t **head2)
{
    if ((*head)->next != NULL)
        (*head)->nb = (*head)->nb - (*head)->next->nb;
    remove_node(*head);
    if ((*head2)->next != NULL) {
        (*head2)->ope = (*head2)->next->ope;
        (*head2)->priority = (*head2)->next->priority;
        remove_node2(*head2);
    }
}

void calculadd(nb_list_t **head, ope_list_t **head2)
{
    if ((*head)->next != NULL)
        (*head)->nb = (*head)->nb + (*head)->next->nb;
    remove_node(*head);
    if ((*head2)->next != NULL) {
        (*head2)->ope = (*head2)->next->ope;
        (*head2)->priority = (*head2)->next->priority;
        remove_node2(*head2);
    }
}

void calculmul(nb_list_t **head, ope_list_t **head2)
{
    if ((*head)->next != NULL)
        (*head)->nb = (*head)->nb * (*head)->next->nb;
    remove_node(*head);
    if ((*head2)->next != NULL) {
        (*head2)->ope = (*head2)->next->ope;
        (*head2)->priority = (*head2)->next->priority;
        remove_node2(*head2);
    }
}
