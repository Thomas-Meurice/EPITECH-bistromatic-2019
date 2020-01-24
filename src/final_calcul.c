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
#include <stdio.h>
#include <stdlib.h>

void final_calcul(nb_list_t **head, ope_list_t **head2)
{
    while ((*head)->next != NULL) {
        if ((*head2)->ope == '*')
            calculmul(head, head2);
        if ((*head2)->ope == '/')
            calculdiv(head, head2);
        if ((*head2)->ope == '%')
            calculmod(head, head2);
        pass_parentheses(head, head2);
    }
    while ((*head2)->prev != NULL)
        *head2 = (*head2)->prev;
    while ((*head)->prev != NULL)
        *head = (*head)->prev;
    while ((*head)->next != NULL) {
        if ((*head2)->ope == '+')
            calculadd(head, head2);
        if ((*head2)->ope == '-')
            calculsub(head, head2);
    }
}