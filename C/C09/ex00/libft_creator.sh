#!/bin/sh
gcc -Wall -Werror -Wextra -c ft_putchar.c ft_strcmp.c ft_swap.c ft_putstr.c ft_strlen.c 
ar -crs libft.a ft_putchar.o ft_strcmp.o ft_swap.o ft_putstr.o ft_strlen.o 
rm ft_putchar.o ft_strcmp.o ft_swap.o ft_putstr.o ft_strlen.o 
