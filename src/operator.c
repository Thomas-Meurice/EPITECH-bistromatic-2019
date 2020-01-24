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

int priority_order(char ope)
{
    int priority;

    if (ope == '-' || ope == '+')
        priority = 1;
    if (ope == '*' || ope == '/' || ope == '%')
        priority = 2;
    if (ope == '(')
        priority = 3;
    if (ope == ')')
        priority = 4;
    return (priority);
}

int operator_in_list(ope_list_t *head, int priority, char ope)
{
    ope_list_t *new;

    new = malloc(sizeof(ope_list_t));
    if (new == NULL)
        return (84);
    new->priority = priority;
    new->ope = ope;
    new->next = NULL;
    while (head->next != NULL)
        head = head->next;
    head->next = new;
    new->prev = head;
    return (0);
}

void ope_list(nb_list_t **head, char const *str)
{
    ope_list_t *head2 = malloc(sizeof(ope_list_t));
    int prio;
    char ope;
    int i = 0;

    for (; str[i] >= '0' && str[i] <= '9'; i++);
    head2->ope = str[i];
    head2->priority = priority_order(str[i]);
    head2->prev = NULL;
    head2->next = NULL;
    i++;
    for (; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9') {
            prio = priority_order(str[i]);
            ope = str[i];
            operator_in_list(head2, prio, ope);
            head2 = head2->next;
        }
    priority(head, head2);
}
