NAME = libft.a

C_FILES = ft_strcpy.c \
ft_strchr.c \
ft_putchar.c \
ft_putnbr.c \
ft_memset.c \
ft_putstr.c \
ft_strlen.c \
ft_isdigit.c \
ft_atoi.c \
ft_bzero.c \
ft_strncpy.c \
ft_strstr.c \
ft_strcmp.c \
ft_strncmp.c \
ft_strcat.c \
ft_strncat.c \
ft_tolower.c \
ft_toupper.c \
ft_isprint.c \
ft_isascii.c \
ft_isalpha.c \
ft_isalnum.c \
ft_strnstr.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memmove.c \
ft_strdup.c \
ft_memchr.c \
ft_memcmp.c \
ft_strlcat.c \
ft_strrchr.c \
ft_memalloc.c \
ft_memdel.c \
ft_strnew.c \
ft_strdel.c \
ft_strclr.c \
ft_striter.c \
ft_striteri.c \
ft_strmap.c \
ft_strmapi.c \
ft_strequ.c \
ft_strnequ.c \
ft_strsub.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strsplit.c \
ft_itoa.c \
ft_putendl.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lstmap.c \
ft_any.c \
ft_isspace.c \
ft_count_if.c \
ft_foreach.c \
ft_map.c \
ft_recursive_factorial.c \
ft_recursive_power.c \
ft_sqrt.c \
ft_strrev.c \
ft_swap.c \
ft_itoa_base.c \
ft_strchlen.c \
ft_strdiv.c \
ft_numlen.c \
ft_stroneleft.c \
ft_strnfill.c \
ft_putwstr.c \
ft_wstrlen.c \
ft_wstrdup.c \
ft_wstrcpy.c \
ft_wstrnew.c \
ft_wstrnfill.c \
ft_wstrjoin.c \
ft_longlongtoa.c \
ft_uitoa_base.c \
ft_putwchar.c \
ft_addtoa.c \
ft_ftoa.c \
ft_round.c \
ft_avany.c \
ft_hasnondigits.c \
ft_atoll.c \
get_next_line.c

O_FILES = $(C_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(O_FILES)
	ar -rc $(NAME) $(O_FILES)

$(O_FILES): $(C_FILES)
	gcc -Wall -Werror -Wextra -c $(C_FILES)

clean:
	/bin/rm -f $(O_FILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all