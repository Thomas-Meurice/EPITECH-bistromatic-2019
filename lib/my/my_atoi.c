/*
** EPITECH PROJECT, 2019
** my_atoi
** File description:
** atoi
*/

int my_atoi(char *str)
{
    int	i = 0;
    int	j = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            for (; str[i] >= '0' && str[i] <= '9'; i++)
                j = ((j * 10) + (str[i] - '0'));
            return (j);
	}
        else
            i++;
    }
    return (0);
}
