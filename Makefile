OBJSERVER	:=	server.o \

OBJCLIENT	:=	client.o \

LIBFT_A		:=	libft/libft.a
NAME		:=	server
CLIENT		:=	client

CFLAGS		:=	-Wall -Wextra -Werror

all			:	libgen $(NAME) $(CLIENT)

libgen		:
	@make -C libft

$(NAME)		:	minitalk.h $(OBJSERVER)
	$(CC) $(OBJSERVER) $(LIBFT_A) $(CFLAGS) $(SFLAGS) -o $(NAME)

$(CLIENT)	:	minitalk.h $(OBJCLIENT)
	$(CC) $(OBJCLIENT) $(LIBFT_A) $(CFLAGS) $(SFLAGS) -o $(CLIENT)

%.o			:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	rm -f $(OBJSERVER) $(OBJCLIENT)
	make clean -C libft

fclean		:	clean
	rm -f $(NAME) $(CLIENT)
	make fclean -C libft

re			:	fclean all

.PHONY		:	all clean fclean re