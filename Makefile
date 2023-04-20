DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iheaders -g3 -fsanitize=address

SOURCE = controls.c \
		 errors.c \
		 graphics.c \
		 map.c \
		 so_long.c \
		 gnl/get_next_line.c \
		 gnl/get_next_line_utils.c \

LIBRARY = -lmlx -framework OpenGL -framework AppKit

%.o: %.c
			@echo "${BLUE} ◎ $(YELLOW)Compiling   ${RED}→   $(GREEN)$< $(DEF_COLOR)"
			@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SOURCE:.c=.o}

all: ${NAME}
	
${NAME}: ${OBJS}
	@$(CC) $(SOURCE) $(LIBRARY) -o $(NAME)
	@echo "\n$(GREEN) Created $(NAME) ✓$(DEF_COLOR)\n"

clean:
		@${RM} ${OBJS}
		@echo "\n${GRAY} ◎ $(RED)All objects cleaned successfully ${GRAY}◎$(DEF_COLOR)\n"

fclean: 
		@${RM} ${NAME}
		@${RM} ${OBJS}
		@echo "\n${GRAY} ◎ $(RED)All objects and executable cleaned successfully${GRAY} ◎$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re