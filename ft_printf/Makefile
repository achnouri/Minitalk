NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Werror -Wextra
ARV = ar -rc
RM = RM -f

SRC = ft_puthexnum.c ft_putptr.c ft_putunbr.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(ARV) $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) -c $(FLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re