/*
** EPITECH PROJECT, 2019
** test_my_infinadd
** File description:
** test for infinadd
*/

#include <criterion/criterion.h>

char *eval_expr(char const *str);

Test(eval_expr, test_for_evalexpr_0)
{
    char const *str = "10+1";

    cr_assert_str_eq(eval_expr(str), "11");
}

Test(eval_expr, test_for_evalexpr_1)
{
    char const *str = "9+1";

    cr_assert_str_eq(eval_expr(str), "10");
}

Test(eval_expr, test_for_evalexpr_2)
{
    char const *str = "100-1";

    cr_assert_str_eq(eval_expr(str), "99");
}

Test(eval_expr, test_for_evalexpr_3)
{
    char const *str = "100*0";

    cr_assert_str_eq(eval_expr(str), "0");
}
