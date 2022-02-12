NAME_SERVER = server

NAME_CLIENT = client

NAME_LIBFT = libftprintf.a

HEADER = minitalk.h printf/ft_printf.h printf/libft/libft.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC_SERVER = server.c 

SRC_CLIENT = client.c

SRC_LIBFT = printf/ft_printf_utils.c printf/ft_printf.c \
		printf/ft_printf_utils2.c printf/ft_printf_print_ptr.c \
		printf/ft_printf_print_unsigned.c \
		printf/libft/ft_bzero.c printf/libft/ft_strlcat.c \
		printf/libft/ft_isalnum.c printf/libft/ft_isalpha.c \
		printf/libft/ft_isascii.c printf/libft/ft_isdigit.c \
		printf/libft/ft_isprint.c printf/libft/ft_memchr.c \
		printf/libft/ft_memcmp.c printf/libft/ft_memcpy.c \
		printf/libft/ft_toupper.c printf/libft/ft_memset.c \
		printf/libft/ft_tolower.c printf/libft/ft_strrchr.c\
		printf/libft/ft_strncmp.c printf/libft/ft_strdup.c \
		printf/libft/ft_strchr.c printf/libft/ft_strlen.c \
		printf/libft/ft_calloc.c printf/libft/ft_memmove.c \
		printf/libft/ft_strtrim.c printf/libft/ft_putchar_fd.c \
		printf/libft/ft_putendl_fd.c printf/libft/ft_putstr_fd.c\
		printf/libft/ft_atoi.c printf/libft/ft_strlcpy.c \
		printf/libft/ft_strnstr.c printf/libft/ft_putnbr_fd.c \
		printf/libft/ft_strmapi.c printf/libft/ft_strjoin.c \
		printf/libft/ft_substr.c printf/libft/ft_itoa.c \
        printf/libft/ft_striteri.c printf/libft/ft_split.c \

.PHONY: all clean fclean re norm 

OBJS_LIBFT = $(SRC_LIBFT:.c=.o)

OBJS_SERVER = $(SRC_SERVER:.c=.o)

OBJS_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(NAME_LIBFT) $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_LIBFT) : $(OBJS_LIBFT) $(HEADER)
	ar rcs $(NAME_LIBFT) $(OBJS_LIBFT)

$(NAME_CLIENT) : $(OBJS_CLIENT) $(HEADER)
	gcc $(CFLAGS)  $(OBJS_CLIENT) $(NAME_LIBFT) -o $(NAME_CLIENT)

$(NAME_SERVER) : $(OBJS_SERVER) $(HEADER)
	gcc $(CFLAGS)  $(OBJS_SERVER) $(NAME_LIBFT) -o $(NAME_SERVER)

%.o:%.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_LIBFT)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_LIBFT)

re: fclean all

norm:
	norminette $(SRC_CLIENT) $(SRC_SERVER) $(LIBFT_NAME)
