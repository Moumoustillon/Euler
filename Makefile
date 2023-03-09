##
## sokoban
## File description:
## makefile
##

SRC =     src/reader.c \

MAIN = src/main.c \

TEST = unit_tests
TESTS = \
CC = gcc
OBJ = $(SRC:.c=.o)
MAINOBJ = $(MAIN:.c=.o)

NAME = my_sokoban
CFLAGS = -I include/
LIB = lib/libmy.a
CFLAGS += -Wall -Wextra -g3

all: $(NAME)

$(NAME): $(OBJ) $(MAINOBJ)
    make re -C lib/my/
    $(CC) -o $(NAME) $(OBJ) $(MAINOBJ) $(LIB) $(CFLAGS) $(LDFLAGS)

re: fclean all

clean:
    rm -f $(OBJ)
    rm -f $(MAINOBJ)

fclean: clean
    rm -f $(NAME)

tests_run:
    ./tests

.PHONY: all re clean fclean tests_run