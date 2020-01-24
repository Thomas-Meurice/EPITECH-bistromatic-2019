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

void pass_parentheses(nb_list_t **head, ope_list_t **head2)
{
    if ((*head)->next != NULL && (*head2)->ope != '*' &&
        (*head2)->ope != '/' && (*head2)->ope != '%' &&
        (*head2)->ope != '(' && (*head2)->ope != ')')
        *head = (*head)->next;
    if ((*head2)->next != NULL && (*head2)->ope != '*' &&
        (*head2)->ope != '/' && (*head2)->ope != '%' &&
        (*head2)->ope != '(' && (*head2)->ope != ')')
        *head2 = (*head2)->next;
}

void sup_parentheses(nb_list_t **head, ope_list_t **head2)
{
    if ((*head2)->ope == ')') {
        *head2 = (*head2)->prev;
        remove_node2(*head2);
    }
    if ((*head2)->ope == '(') {
        if ((*head2)->prev != NULL) {
            *head2 = (*head2)->prev;
            remove_node2(*head2);
        }
        if ((*head2)->prev == NULL && (*head2)->next != NULL) {
            (*head2)->ope = (*head2)->next->ope;
            (*head2)->priority = (*head2)->next->priority;
            remove_node2(*head2);
        }
    }
    while ((*head2)->prev != NULL)
        *head2 = (*head2)->prev;
    while ((*head)->prev != NULL)
        *head = (*head)->prev;
}

void parentheses_sec(nb_list_t **head, ope_list_t **head2)
{
    *head2 = (*head2)->prev;
    while ((*head2)->priority != 3) {
        *head = (*head)->prev;
        *head2 = (*head2)->prev;
    }
    *head2 = (*head2)->next;
    while ((*head2)->priority != 4) {
        if ((*head2)->ope == '+')
            calculadd(head, head2);
        if ((*head2)->ope == '-')
            calculsub(head, head2);
    }
    sup_parentheses(head, head2);
}

void parentheses(nb_list_t **head, ope_list_t **head2)
{
    *head2 = (*head2)->prev;
    while ((*head2)->priority != 3) {
        *head = (*head)->prev;
        *head2 = (*head2)->prev;
    }
    *head2 = (*head2)->next;
    while ((*head2)->ope != ')') {
        if ((*head2)->ope == '*')
            calculmul(head, head2);
        if ((*head2)->ope == '/')
            calculdiv(head, head2);
        if ((*head2)->ope == '%')
            calculmod(head, head2);
        pass_parentheses(head, head2);
    }
    parentheses_sec(head, head2);
}

void priority(nb_list_t **head, ope_list_t *head2)
{
    while (head2->prev != NULL)
        head2 = head2->prev;
    while ((*head)->prev != NULL)
        *head = (*head)->prev;
    if (head2->priority == 3)
        head2 = head2->next;
    while (head2->next != NULL) {
        if (head2->priority == 3)
            head2 = head2->next;
        if ((*head)->next != NULL)
            *head = (*head)->next;
        head2 = head2->next;
        if (head2->priority == 4)
            parentheses(head, &head2);
    }
    while (head2->prev != NULL)
        head2 = head2->prev;
    while ((*head)->prev != NULL)
        *head = (*head)->prev;
    final_calcul(head, &head2);
    free(head2);
}