/*
** EPITECH PROJECT, 2019
** nb_parenthesis
** File description:
** number of parenthesis
*/

int nb_parenthesis(char *str)
{
    int count_open = 0;
    int count_close = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            count_open += 1;
        if (str[i] == ')')
            count_close += 1;
    }
    if (count_open == count_close)
        return (1);
    else
        return (0);
}
