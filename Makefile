SRCS = 	conv_check.c \
		flag_manager.c \
		ft_initialise_tab.c \
		ft_itoa_base.c \
		ft_printf.c \
		helpers.c \
		num_printing.c \
		printers.c \
		helpers_lib.c \
		abc_printers.c \
		z_flag_printers.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I -c

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

bonus: all

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
