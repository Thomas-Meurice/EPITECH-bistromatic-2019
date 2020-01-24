/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** {description}
*/

#include "my.h"
#include "nb_list.h"
#include "ope_list.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int error_management(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < '0' || str[i] > '9') && str[i] != '(' && str[i] != ')' &&
            str[i] != '*' && str[i] != '/' && str[i] != '%' && str[i] != '+' &&
            str[i] != '-')
            return (1);
    return (0);
}

int my_strtol(char const *str, int *i)
{
    int j = my_getnbr(str);

    if (str[0] == '(')
        ((*i)++);
    if (str[0] == '-' && str[1] == '(') {
        ((*i)++);
        ((*i)++);
    }
    for (; str[*i] >= '0' && str[*i] <= '9'; (*i)++);
    return (j);
}

int my_put_in_list(nb_list_t *head, int nb)
{
    nb_list_t *new;

    new = malloc(sizeof(nb_list_t));
    if (new == NULL)
        return (84);
    new->nb = nb;
    new->next = NULL;
    while (head->next != NULL)
        head = head->next;
    head->next = new;
    new->prev = head;
    return (0);
}

int eval_expr(char const *str)
{
    nb_list_t *head = malloc(sizeof(nb_list_t));
    int nb;
    int i = 0;

    head->nb = my_strtol(&str[i], &i);
    head->prev = NULL;
    head->next = NULL;
    for (; str[i] != '\0'; i++)
        if ((str[i] >= '0' && str[i] <= '9') &&
            (str[i - 1] < '0' || str[i - 1] > '9')) {
            nb = my_strtol(&str[i], &i);
            my_put_in_list(head, nb);
            head = head->next;
        }
    ope_list(&head, str);
    nb = head->nb;
    free(head);
    return (nb);
}
