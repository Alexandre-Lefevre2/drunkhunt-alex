## Makefile
## Drunkhunt

SRC	=	src/main.c		

OBJ	=	$(SRC:.c=.o)

CFLAGS = -g3 -Wall -Wextra -Wconversion -Wno-unused-parameter -lcsfml-system -lcsfml-graphics -lcsfml-window

NAME	=	drunkhunt

all:	$(NAME)

$(NAME): $(OBJ) $(OBJ_FLAG)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
