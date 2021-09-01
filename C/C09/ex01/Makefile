NAME = libft.a

SRCS = 					\
	srcs/ft_putchar.c	\
	srcs/ft_putstr.c	\
	srcs/ft_swap.c		\
	srcs/ft_strlen.c	\
	srcs/ft_strcmp.c

OBJS :=$(SRCS:.c=.o)

INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar -crs $@ $^

%.o: %.c
	gcc $(CFLAGS) -c $< -I$(INCLUDES) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
