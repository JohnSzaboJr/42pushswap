/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:20:40 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/23 15:01:07 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

typedef struct				s_list_num
{
	int						num;
	struct s_list_num		*next;
}							t_list_num;

int							throw_error(void);
int							ps_check_input(int argc, char **argv);
int							ps_not_int_size(char *str);
int							ps_instruction(t_list_num **list,
	t_list_num **blist, char *line);
int							ps_duplicates(t_list_num *list, int num);
int							make_list(int argc, char **argv, t_list_num **list);
int							ps_no_input(int i);
int							ps_check_sort(t_list_num *list, int n);
int							ps_free(t_list_num **list);
int							ps_read_do(char **line, t_list_num **list,
	t_list_num **blist);
void						ps_ins_switch(t_list_num **list);
void						ps_ins_switch_both(t_list_num **alist,
	t_list_num **blist);
void						ps_ins_push(t_list_num **dstlist,
	t_list_num **srclist);
void						ps_ins_rotate(t_list_num **list);
void						ps_ins_rotate_both(t_list_num **alist,
	t_list_num **blist);
void						ps_ins_rrotate(t_list_num **list);
void						ps_ins_rrotate_both(t_list_num **alist,
	t_list_num **blist);
int							ps_solve(t_list_num **list, t_list_num **blist);
void						ps_select_sort(t_list_num **ins,
	t_list_num **list, t_list_num **blist);
int							ps_smallest(t_list_num *list);
int							ps_add_list(t_list_num **list, int num);
int							ps_size(t_list_num *list);
int							ps_not_sort(t_list_num *list);
int							ps_relative_sort(t_list_num **ins,
	t_list_num **list);
void						ps_print_ins(t_list_num *ins);
int							ps_convert_ins(t_list_num **ins);
int							ps_reverse_list(t_list_num **ins);
int							ps_num(t_list_num *list, int pos);
int							ps_median(t_list_num *list, int start, int end);
int							ps_position(t_list_num *list, int n);
void						ps_split_sort(t_list_num **ins, t_list_num **list);
void						ps_rrotate_n(t_list_num **list, int n,
	t_list_num **ins);
void						ps_rrotate_n2(t_list_num **list, int n,
	t_list_num **ins);
void						ps_rotate_n(t_list_num **list, int	n,
	t_list_num **ins);
void						ps_rotate_n2(t_list_num **list, int	n,
	t_list_num **ins);
void						ps_rotate_into_place(t_list_num **list, int end,
	int last, t_list_num **ins);
void						ps_rotate_into_place2(t_list_num **list, int end,
	int last, t_list_num **ins);
int							ps_largest_num(t_list_num *list);
int							ps_elements_larger(t_list_num *list, int n);
int							ps_elements_smaller(t_list_num *list, int n);
int							ps_push_med(t_list_num **src, t_list_num **trg,
	t_list_num **ins, int s);
int							ps_push_med2(t_list_num **src, t_list_num **trg,
	t_list_num **ins);
void						ps_rrb(t_list_num **blist, t_list_num **ins);
void						ps_rra(t_list_num **list, t_list_num **ins);
void						ps_rb(t_list_num **blist, t_list_num **ins);
void						ps_ra(t_list_num **list, t_list_num **ins);
void						ps_pb(t_list_num **blist, t_list_num **list,
	t_list_num **ins);
void						ps_pa(t_list_num **list, t_list_num **blist,
t_list_num **ins);
void						ps_sa(t_list_num **list, t_list_num **ins);
void						ps_sb(t_list_num **blist, t_list_num **ins);
void						ps_pmb(t_list_num **list, t_list_num **blist,
	t_list_num **ins);
void						ps_pmb2(t_list_num **list, t_list_num **blist,
	t_list_num **ins);
void						ps_fsort(t_list_num **list, t_list_num **blist,
	t_list_num **ins);
void						ps_endsplit(t_list_num **list, t_list_num **blist,
	t_list_num **ins);
void						ps_transsplit(t_list_num **list, t_list_num **blist,
	t_list_num **ins);
void						ps_transback(t_list_num **list, t_list_num **blist,
	t_list_num **ins);
int							ps_sortinb(t_list_num **list, t_list_num **blist,
	t_list_num **ins, int l);
void						ps_resplit(t_list_num **list, t_list_num **blist,
	t_list_num **ins, int m);
void						ps_resplit2(t_list_num **list, t_list_num **blist,
	t_list_num **ins, int m);
int							ps_distance1(t_list_num *list, t_list_num *blist);
int							ps_distance2(t_list_num *list, t_list_num *blist);
int							ps_distance3(t_list_num *blist, int n);
void						ps_overwrite(t_list_num **ins, int a, int b);
void						ps_normalize(t_list_num **list);
void						ps_g_l(t_list_num **list, t_list_num **blist,
	t_list_num **ins, int a);
void						ps_g_s(t_list_num **list, t_list_num **blist,
	t_list_num **ins, int b);
int							ps_get_input(int argc, char **argv,
	t_list_num **list);
int							ps_avany(char **argv, int argc, int (*f)(char*));
void						ps_small_sort(t_list_num **ins, t_list_num **list);
int							ps_null(t_list_num *list);
void						ps_print_list(t_list_num *list);

#endif
