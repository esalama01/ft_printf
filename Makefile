CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c src/ft_hex.c src/ft_hexupper.c src/ft_putchar.c src/ft_putnbr.c \
 		src/ft_putstr.c src/ft_uputnbr.c src/ft_void.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
HEADER = ft_printf.h

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all