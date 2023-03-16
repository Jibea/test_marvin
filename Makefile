##
## EPITECH PROJECT, 2023
## B-ASM-400-NAN-4-1-asmminilibc-guylain.thomas [WSL : Ubuntu]
## File description:
## Makefile
##

SRC = strlen.asm \
	  strchr.asm \
	  strrchr.asm \
	  strcmp.asm  \
	  strncmp.asm \
	  strpbrk.asm \
	  strcspn.asm \
	  strstr.asm \
	  strcasecmp.asm \
#	  memset.asm
#	  memcpy.asm  \
#	  memmove.asm

SRC_TEST =  tests/test_strchr.c \
		   	tests/test_strcmp.c  \
		   	tests/test_strncmp.c  \
		   	tests/test_strpbrk.c  \
		   	tests/test_strcspn.c  \
		   	tests/test_strstr.c \
 		 	tests/test_strcasecmp.c
#			tests/test_memmove.c   
# 			tests/test_memset.c


OBJ = $(SRC:.asm=.o)
OBJTEST = $(SRC_TEST:.c=.o)

NAME = libasm.so
NAME_TEST = unit_tests


$(NAME):
	nasm -f elf64 strlen.asm
	nasm -f elf64 strchr.asm
	nasm -f elf64 strrchr.asm
	nasm -f elf64 memset.asm
#	nasm -f elf64 memcpy.asm
	nasm -f elf64 strcmp.asm
	nasm -f elf64 strncmp.asm
	nasm -f elf64 strcasecmp.asm
	nasm -f elf64 strpbrk.asm
	nasm -f elf64 strcspn.asm
	nasm -f elf64 strstr.asm
#	nasm -f elf64 memmove.asm
	ld -shared -o $(NAME) $(OBJ)

all: $(NAME)


compile: $(NAME)
	gcc main.c -I/include libasm.so -ldl

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f a.out
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno
	rm -f $(NAME_TEST)

test_run: $(NAME)
	mv libasm.so tests
	gcc -o $(NAME_TEST) $(SRC_TEST) -I/include tests/libasm.so -lcriterion -ldl

re: fclean all

.PHONY: all clean fclean re