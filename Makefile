OBJCS		:=

LIBFT		:=	libft/libft.a

NAME		:=	so_long
CFLAGS		?=	-Wall -Wextra -Werror
SFLAGS		:=	

all			:	$(NAME)

$(NAME)		:	$(OBJCS)
	$(CC) $(OBJCS) $(LIBFT) $(CFLAGS) $(SFLAGS) -o $(NAME)

%.o			:	%.c
	$(CC) $(CFLAGS) -c $< -o $@


clean		:
	rm -f $(OBJCS)

fclean		:	clean
	rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re