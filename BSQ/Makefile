NAME=bsq
CC=gcc
RM=rm -rf
FLAGS=-Wall -Wextra -Werror
SRC=src
INCLUDE=include
C_FILES=main.c ft_bsq.c ft_map_utils.c ft_map_utils1.c utils.c
O_FILES=$(C_FILES:%.c=%.o)
all: $(NAME)


$(NAME):
	cd $(SRC);$(CC) $(FLAGS) -c $(C_FILES) -I../$(INCLUDE)
	cd $(SRC);$(CC) $(FLAGS) $(O_FILES) -o ../$@ -I../$(INCLUDE)

clean:
	cd $(SRC);$(RM) $(O_FILES)

fclean: clean
	$(RM) $(NAME)
re:	fclean all
