CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

NAME = pipex

SRCS = utils_c/tools.c utils_c/libft_utils.c  utils_c/get_next_line.c \
	utils_c/get_next_line_utils.c ft_printf/ft_printf.c ft_printf/ft_decimal_to_hex.c \
	ft_printf/ft_check.c ft_printf/ft_decimal_to_hexa.c ft_printf/ft_put_positive.c \
	ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/ft_put_adress.c ft_printf/ft_putchar.c \
	ft_pipe.c if_accessible.c main.c
	
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
