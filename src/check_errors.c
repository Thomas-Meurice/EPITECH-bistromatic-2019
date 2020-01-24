/*
** EPITECH PROJECT, 2019
** check_errors
** File description:
** check errors with parenthesis
*/

int check_errors(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '(' && i != 0 && str[i - 1] != '+' &&
            str[i - 1] != '-' && str[i - 1] != '*' &&
            str[i - 1] != '/' && str[i - 1] != '%' &&
            str[i - 1] != '(')
            return (1);
    return (0);
}

int check_div_mod_zero(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (i != 0 && str[i] == '0' &&
            (str[i - 1] == '/' || str[i - 1] == '%'))
            return (1);
    return (0);
}

int check_diff_bases(char *bases)
{
    char *origin = "()+-*/%";

    for (int i = 0; bases[i] != '\0'; i++)
        if (bases[i] != origin[i])
            return (1);
    return (0);
}
