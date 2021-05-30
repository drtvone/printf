NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror


HEADER = ./project_printf/my_printf.h

FILES =	my_printf.c \
			my_printf_parse_flags.c \
			libft_utils.c \
			ft_libft_utils.c \
			printf_char.c \
			printf_string.c \
			printf_uns.c \
			printf_int.c \
			ft_itoa.c \
			printf_hex.c \
			printf_pointer.c \
			help_funcs.c

SRCS_DIR = project_printf

SRCS = $(addprefix $(SRCS_DIR)/, $(FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re