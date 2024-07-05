NAME = push_swap

SOURCES = src/allocation.c src/ins.c src/main.c src/simple_sort.c \
src/utils_1.c src/utils_2.c src/radix.c src/lists.c  \
src/ins_lst.c src/ft_split.c src/utils_3.c\

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	rm -f src/*.o

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re