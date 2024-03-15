NAME = so_long

SRCS = src/main.c \
	   src/ft_pars.c \
	   src/get_next_line.c \
	   src/get_next_line_utils.c \
	   src/ft_mapvalid.c \
	   src/ft_collectvalid.c \
	   src/start_game.c \
	   src/ft_graphic.c \
	   src/ft_move.c \
	   src/exit_game.c \
	   src/ft_util_split.c \
	   src/ft_util_itoa.c \
	   src/ft_util_trim.c \
	   src/ft_util_trim2.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror 
LDFLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

%.o: %.c Includes/so_long.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re