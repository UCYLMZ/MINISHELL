SRCS		=		main.c minishell_exec.c utils_signal.c file_process.c utils_list.c list_initializer.c utils_modified.c utils_format.c

LIBFT		=		-I./libft

OBJS		=		$(SRCS:.c=.o)

NAME		=		minishell

CC			=		gcc

CFLAGS		=		-I./lib/readline/include

RM			=		rm -rf

LDFLAGS = -L./lib/readline/lib -lreadline

LIB = ./lib/.minishell

all:	$(LIB)	$(NAME) $(LIBFT)

$(LIBFT):
			make bonus -C ./libft

$(NAME):	$(OBJS) $(LIBFT) 
				$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(LDFLAGS) -o $(NAME)

$(LIB):
	@make -C ./lib

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)
			make fclean -C libft

ffclean:
		make fclean
		make fclean ./lib

re:			fclean all

.PHONY:		all clean fclean re