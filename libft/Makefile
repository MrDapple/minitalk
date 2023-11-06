OBJCS		:=	ft_atoi.o \
				ft_isalpha.o \
				ft_isprint.o \
				ft_strchr.o \
				ft_strlen.o \
				ft_strrchr.o \
				ft_isascii.o \
				ft_strncmp.o \
				ft_tolower.o \
				ft_isalnum.o \
				ft_isdigit.o \
				ft_strlcpy.o \
				ft_toupper.o \
				ft_memset.o \
				ft_bzero.o \
				ft_memcpy.o \
				ft_memmove.o \
				ft_memcmp.o \
				ft_memchr.o \
				ft_strnstr.o \
				ft_calloc.o \
				ft_strdup.o \
				ft_substr.o \
				ft_strlcat.o \
				ft_strjoin.o \
				ft_strtrim.o \
				ft_itoa.o \
				ft_strmapi.o \
				ft_striteri.o \
				ft_putchar_fd.o \
				ft_putstr_fd.o \
				ft_putnbr_fd.o \
				ft_putendl_fd.o \
				ft_split.o \
				get_next_line.o \
				get_next_line_utils.o \
				ft_lstnew_bonus.o \
				ft_lstadd_front_bonus.o \
				ft_lstsize_bonus.o \
				ft_lstlast_bonus.o \
				ft_lstadd_back_bonus.o \
				ft_lstdelone_bonus.o \
				ft_lstclear_bonus.o \
				ft_lstiter_bonus.o \
				ft_lstmap_bonus.o \
				ft_printf.o \
				ft_printf_char.o \
				ft_printf_nb.o \
				ft_printf_str.o \
				ft_printf_void.o \
				ft_printf_unsigned.o \
				ft_printf_lower_hex.o \
				ft_printf_upper_hex.o \

NAME		:=	libft.a
CFLAGS		:=	-Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJCS) libft.h
	ar -rcs $(NAME) $(OBJCS)

%.o			:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	rm -f $(OBJCS)

fclean		:	clean
	rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re