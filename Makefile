#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jszabo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 10:11:43 by jszabo            #+#    #+#              #
#    Updated: 2018/06/06 10:11:45 by jszabo           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = $(CHECKER) $(PUSH_SWAP)
CHECKER = checker
PUSH_SWAP = push_swap
LIBFT = libft/libft.a
FLAGS = -Wall -Werror -Wextra
SRCS = srcs/
MAINS = checker push_swap
SOURCES = ps_add_list ps_check_input ps_check_sort ps_convert_ins \
ps_distance1 ps_distance2 ps_distance3 ps_duplicates ps_elements_larger \
ps_elements_smaller ps_endsplit ps_free ps_fsort ps_ins_push \
ps_ins_rotate ps_ins_rrotate ps_ins_switch ps_instruction \
ps_largest_num ps_make_list ps_median ps_no_input ps_normalize \
ps_not_int_size ps_not_sort ps_num ps_overwrite ps_pa ps_pb ps_pmb \
ps_pmb2 ps_position ps_print_ins ps_print_list ps_push_med \
ps_push_med2 ps_ra ps_rb ps_read_do ps_relative_sort ps_resplit \
ps_resplit2 ps_reverse_list ps_rotate_into_place ps_rotate_into_place2 \
ps_rotate_n ps_rotate_n2 ps_rra ps_rrb ps_rrotate_n ps_rrotate_n2 ps_sa \
ps_sb ps_selec_sort ps_size ps_smallest ps_solve ps_sortinb \
ps_split_sort ps_throw_error ps_transback ps_transsplit ps_g_l ps_g_s \
ps_get_input ps_avany ps_small_sort ps_free_tab
C_FILES = $(patsubst %,$(SRCS)%.c, $(SOURCES)) $(patsubst %,%.c, $(MAINS))
O_FILES = $(patsubst %,%.o, $(SOURCES)) $(patsubst %,%.o, $(MAINS))
SHARED_O = $(patsubst %,objects/%.o, $(SOURCES))

LIBFTSRC = libft/ft_strcpy.c \
libft/ft_strchr.c \
libft/ft_putchar.c \
libft/ft_putnbr.c \
libft/ft_memset.c \
libft/ft_putstr.c \
libft/ft_strlen.c \
libft/ft_isdigit.c \
libft/ft_atoi.c \
libft/ft_bzero.c \
libft/ft_strncpy.c \
libft/ft_strstr.c \
libft/ft_strcmp.c \
libft/ft_strncmp.c \
libft/ft_strcat.c \
libft/ft_strncat.c \
libft/ft_tolower.c \
libft/ft_toupper.c \
libft/ft_isprint.c \
libft/ft_isascii.c \
libft/ft_isalpha.c \
libft/ft_isalnum.c \
libft/ft_strnstr.c \
libft/ft_memcpy.c \
libft/ft_memccpy.c \
libft/ft_memmove.c \
libft/ft_strdup.c \
libft/ft_memchr.c \
libft/ft_memcmp.c \
libft/ft_strlcat.c \
libft/ft_strrchr.c \
libft/ft_memalloc.c \
libft/ft_memdel.c \
libft/ft_strnew.c \
libft/ft_strdel.c \
libft/ft_strclr.c \
libft/ft_striter.c \
libft/ft_striteri.c \
libft/ft_strmap.c \
libft/ft_strmapi.c \
libft/ft_strequ.c \
libft/ft_strnequ.c \
libft/ft_strsub.c \
libft/ft_strjoin.c \
libft/ft_strtrim.c \
libft/ft_strsplit.c \
libft/ft_itoa.c \
libft/ft_putendl.c \
libft/ft_putchar_fd.c \
libft/ft_putstr_fd.c \
libft/ft_putendl_fd.c \
libft/ft_putnbr_fd.c \
libft/ft_lstnew.c \
libft/ft_lstdelone.c \
libft/ft_lstdel.c \
libft/ft_lstadd.c \
libft/ft_lstiter.c \
libft/ft_lstmap.c \
libft/ft_any.c \
libft/ft_isspace.c \
libft/ft_count_if.c \
libft/ft_foreach.c \
libft/ft_map.c \
libft/ft_recursive_factorial.c \
libft/ft_recursive_power.c \
libft/ft_sqrt.c \
libft/ft_strrev.c \
libft/ft_swap.c \
libft/ft_itoa_base.c \
libft/ft_strchlen.c \
libft/ft_strdiv.c \
libft/ft_numlen.c \
libft/ft_stroneleft.c \
libft/ft_strnfill.c \
libft/ft_putwstr.c \
libft/ft_wstrlen.c \
libft/ft_wstrdup.c \
libft/ft_wstrcpy.c \
libft/ft_wstrnew.c \
libft/ft_wstrnfill.c \
libft/ft_wstrjoin.c \
libft/ft_longlongtoa.c \
libft/ft_uitoa_base.c \
libft/ft_putwchar.c \
libft/ft_addtoa.c \
libft/ft_ftoa.c \
libft/ft_round.c \
libft/ft_avany.c \
libft/ft_hasnondigits.c \
libft/ft_atoll.c \
libft/get_next_line.c \
libft/ft_printf.c \
libft/libft.h

all: $(NAME)

$(LIBFT):
	@make -C libft/ all

objects: $(LIBFT) $(LIBFTSRC) $(C_FILES) checker.h
	@gcc $(FLAGS) -c $(C_FILES)
	@mkdir objects/ 2> /dev/null || true
	@mv $(O_FILES) objects/
	@echo '\033[0;32m'*** project objects created ***'\033[0m'

$(CHECKER): objects
	@gcc -o $(CHECKER) ./libft/libft.a $(SHARED_O) ./objects/checker.o
	@echo '\033[0;32m'*** checker compiled ***'\033[0m'

$(PUSH_SWAP): objects
	@gcc -o $(PUSH_SWAP) $(SHARED_O) ./objects/push_swap.o ./libft/libft.a
	@echo '\033[0;32m'*** push_swap compiled ***'\033[0m'

clean: 
	@/bin/rm -rf objects/
	@make -C libft/ clean
	@echo '\033[0;32m'*** project objects removed ***'\033[0m'

fclean: clean
	@/bin/rm -f $(CHECKER) $(PUSH_SWAP)
	@make -C libft/ fclean
	@echo '\033[0;32m'*** project executables removed ***'\033[0m'

re: fclean all