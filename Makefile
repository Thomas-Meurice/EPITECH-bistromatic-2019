##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Thomas Meurice <thomas.meurice@epitech.eu>
##


SRC	=	src/eval_expr.c		\
		src/operator.c		\
		src/priority.c		\
		src/calcul.c		\
		src/final_calcul.c	\
		src/nb_parenthesis.c	\
		src/check_errors.c	\

NAME	=	calc

COMPIL	=	-Llib/my -lmy

TFLAG	=	./tests/test_my_bistro.c -lcriterion --coverage -fprofile-arcs

CFLAGS	=	-I include/ -g

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		make clean -C lib/my
		gcc -o $(NAME) $(SRC) ./src/main.c ./src/main_evalexpr.c $(COMPIL) $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re:		fclean all

tests_run:
		make -C ./lib/my re
		gcc -o $(NAME) $(SRC) $(TFLAG) $(COMPIL) $(CFLAGS)
		-./$(NAME)
		gcovr --exclude tests/
		rm -f *.gcno
		rm -f *.gcda

.PHONY:		all debug clean fclean
