LIBFT = ./libft/libft.a

NAME = checker

SRCS = checker.c\
		check_arg.c\
		get_stdin.c\
		liste.c\
		ft_utils.c\
		ft_commands.c

CC = gcc

FLAGS = -c -Wall -Wextra -Werror 

INCLUDE = push_swap.h

OBJS = $(SRCS:.c=.o)

%.o: %.c $(INCLUDE)
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		cp libft/libft.a .
		$(CC) -o $(NAME) $(SRCS) $(LIBFT)

all : $(NAME)

clean :
		$(MAKE) clean -C ./libft 
		rm -rf *.o

fclean : clean
		$(MAKE) fclean -C ./libft
		rm -rf *.o
		rm -rf *.a
		rm -rf checker

re : fclean all

.PHONY: clean fclean re all