CHECKER = checker
PUSH_SWAP = push_swap
LIBFT = libft/libft.a
FLAGS = -Wall -Werror -Wextra
SRCS = srcs/
MAINS = checker push_swap
SOURCES = ps_add_list ps_check_input ps_check_sort ps_convert_ins \
ps_distance1 ps_distance2 ps_duplicates ps_elements_larger \
ps_elements_smaller ps_endsplit ps_free ps_fsort ps_ins_push \
ps_ins_rotate ps_ins_rrotate ps_ins_switch ps_instruction \
ps_largest_num ps_make_list ps_median ps_no_input ps_normalize \
ps_not_int_size ps_not_sort ps_num ps_overwrite ps_pa ps_pb ps_pmb \
ps_pmb2 ps_position ps_print_ins ps_print_list ps_push_med \
ps_push_med2 ps_ra ps_rb ps_read_do ps_relative_sort ps_resplit \
ps_resplit2 ps_reverse_list ps_rotate_into_place ps_rotate_into_place2 \
ps_rotate_n ps_rotate_n2 ps_rra ps_rrb ps_rrotate_n ps_rrotate_n2 ps_sa \
ps_selec_sort ps_size ps_smallest ps_solve ps_sortinb \
ps_split_sort ps_throw_error ps_transback ps_transsplit
C_FILES = $(patsubst %,$(SRCS)%.c, $(SOURCES)) $(patsubst %,%.c, $(MAINS))
O_FILES = $(patsubst %,%.o, $(SOURCES)) $(patsubst %,%.o, $(MAINS))
SHARED_O = $(patsubst %,objects/%.o, $(SOURCES))

all: $(CHECKER) $(PUSH_SWAP)

$(LIBFT):
	@make -C libft/ all

objects: $(LIBFT)
	@gcc $(FLAGS) -c $(C_FILES) $(MAINS_C)
	@mkdir objects/ 2> /dev/null || true
	@mv $(O_FILES) objects/
	@echo '\033[0;32m'*** project objects created ***'\033[0m'

$(CHECKER): objects
	@gcc -o $(CHECKER) $(SHARED_O) ./objects/checker.o ./libft/libft.a
	@echo '\033[0;32m'*** checker compiled ***'\033[0m'

$(PUSH_SWAP): $(OBJ)
	@gcc -o $(PUSH_SWAP) $(SHARED_O) ./objects/push_swap.o ./libft/libft.a
	@echo '\033[0;32m'*** push_swap compiled ***'\033[0m'

clean: 
	@/bin/rm -rf objects/
	@echo '\033[0;32m'*** project objects removed ***'\033[0m'

fclean: clean
	@/bin/rm -f $(CHECKER) $(PUSH_SWAP)
	@echo '\033[0;32m'*** project executables removed ***'\033[0m'
	@make -C libft/ fclean

re: fclean all