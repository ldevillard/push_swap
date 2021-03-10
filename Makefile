LIBFT = ./libft/libft.a

NAME = checker

NAME2 = push_swap

SRCS_CHECKER = checker_srcs/checker.c\
				checker_srcs/check_arg.c\
				checker_srcs/get_stdin.c\
				checker_srcs/liste.c\
				checker_srcs/ft_utils.c\
				checker_srcs/ft_commands.c

SRCS_PUSHSWAP = pushswap_srcs/push_swap.c\
				pushswap_srcs/ft_utils.c\
				pushswap_srcs/check_arg.c\
				pushswap_srcs/ft_commands.c\
				pushswap_srcs/sort.c\
				pushswap_srcs/liste.c\
				pushswap_srcs/algo.c\
				pushswap_srcs/sort_five.c

CC = gcc

FLAGS = -c -Wall -Wextra -Werror 

INCLUDE = push_swap.h

OBJS = $(SRCS_CHECKER:.c=.o) $(SRCS_PUSHSWAP:.c=.o)

%.o: %.c $(INCLUDE)
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		cp libft/libft.a .
		$(CC) -o $(NAME) $(SRCS_CHECKER) $(LIBFT)
		$(CC) -o $(NAME2) $(SRCS_PUSHSWAP) $(LIBFT)

all : $(NAME)

clean :
		$(MAKE) clean -C ./libft 
		rm -rf *.o
		rm -rf checker_srcs/*.o
		rm -rf pushswap_srcs/*.o

fclean : clean
		$(MAKE) fclean -C ./libft
		rm -rf *.o
		rm -rf checker_srcs/*.o
		rm -rf pushswap_srcs/*.o
		rm -rf *.a
		rm -rf checker
		rm -rf push_swap

re : fclean all

.PHONY: clean fclean re all