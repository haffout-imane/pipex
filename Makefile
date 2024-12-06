NAME = pipex

NAMEB = pipex_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ./mandatory/pipex.c ./mandatory/utils.c ./mandatory/utils2.c ./mandatory/errors.c

SRCSB = ./bonus/pipex_bonus.c ./bonus/utils1_bonus.c ./bonus/utils2_bonus.c\
		./bonus/errors_bonus.c ./bonus/ft_split.c ./bonus/get_next_line.c

OBJ = $(SRCS:.c=.o)

OBJB = $(SRCSB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ./mandatory/pipex.h
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAMEB): $(OBJB) ./bonus/pipex_bonus.h
	$(CC) $(CFLAGS) $(OBJB) -o $(NAMEB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAMEB)

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all

.PHONY: all clean fclean re bonus