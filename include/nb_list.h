/*
** EPITECH PROJECT, 2019
** nb_list
** File description:
** number list
*/

#ifndef _NB_LIST_
#define _NB_LIST_

typedef struct nb_list
{
    int nb;
    struct nb_list *prev;
    struct nb_list *next;
} nb_list_t;

#endif /* _NB_LIST_ */
