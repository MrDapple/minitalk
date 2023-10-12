OBJSERVER	:=	server.o \

OBJCLIENT	:=	client.o \

LIBFT		:=	libft/libft.a

NAME		:=	server
CLIENT		:=	client
CFLAGS		?=	-Wall -Wextra -Werror
SFLAGS		:=

all			:	$(NAME) $(CLIENT)

$(NAME)		:	$(OBJSERVER)
	$(CC) $(OBJSERVER) $(LIBFT) $(CFLAGS) $(SFLAGS) -o $(NAME)

$(CLIENT)	:	$(OBJCLIENT)
	$(CC) $(OBJCLIENT) $(LIBFT) $(CFLAGS) $(SFLAGS) -o $(CLIENT)

%.o			:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	rm -f $(OBJSERVER) $(OBJCLIENT)

fclean		:	clean
	rm -f $(NAME) $(CLIENT)

re			:	fclean all

.PHONY		:	all clean fclean re