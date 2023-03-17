##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Make
##

SRC		=     src/cesar.c		\
		      src/read_file.c		\
		      src/recup_args.c

MAIN    	=     main.c

SRC_TEST 	=     tests/test_s.c

OBJ_TEST 	=     $(SRC_TEST:.c=.o)

NAME_TEST 	=    unit_tests

CC		=    gcc

RM		=    rm -f

OBJ		=    $(SRC:.c=.o)
OBJ    	 	+=   $(MAIN:.c=.o)

NAME		=    cesar

INCLUDES 	=    -Iinclude/

CFLAGS 		=    -Wall -Wextra $(INCLUDES)

MK 		=    make

DEBUG 		=    -g3

all 		:  $(NAME)

$(NAME) 	: $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

debug 		: all
		$(CC) $(DEBUG) -o $(NAME) $(MAIN) $(SRC) $(CFLAGS)

test_run :
		$(CC) -o $(NAME_TEST) $(SRC_TEST) $(CFLAGS)
		-lcriterion -lgcov --coverage
		./$(NAME_TEST)
		-gcovr --exclude tests
		$(RM) *.gc*
		$(RM) tests/*.o

clean 		:
		$(RM) $(OBJ)
		$(RM) *~

fclean 		: clean
		$(RM) $(NAME) $(NAME_TEST)
		$(RM) *.gc*

re		: fclean all

.PHONY 		: all debug clean fclean re
