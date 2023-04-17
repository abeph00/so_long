NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iheaders/

SOURCE = *.c
GETNEXTLINE = GNL/*c
LIBRARY = -lmlx -framework OpenGL -framework AppKit


all:
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
		rm -rf $(NAME)

re: fclean all