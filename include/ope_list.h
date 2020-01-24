/*
** EPITECH PROJECT, 2019
** ope_list
** File description:
** list operators
*/

#ifndef _OPE_LIST_
#define _OPE_LIST_

typedef struct ope_list
{
    char ope;
    int priority;
    struct ope_list *next;
    struct ope_list *prev;
} ope_list_t;

#endif /* _OPE_LIST_ */
