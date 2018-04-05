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
int                         ps_duplicates(t_list_num *list, int num);
int                         make_list(int argc, char **argv, t_list_num **list);
int                         ps_no_input(int i);
int                         ps_check_sort(t_list_num *list, int n);
int                         ps_free(t_list_num **list);
int                         ps_read_do(char **line, t_list_num **list, t_list_num **blist);
void						ps_ins_switch(t_list_num **list);
void						ps_ins_switch_both(t_list_num **alist, t_list_num **blist);
void						ps_ins_push(t_list_num **dstlist, t_list_num **srclist);
void     					ps_ins_rotate(t_list_num **list);
void						ps_ins_rotate_both(t_list_num **alist, t_list_num **blist);
void						ps_ins_rrotate(t_list_num **list);
void						ps_ins_rrotate_both(t_list_num **alist, t_list_num **blist);
int							ps_solve(t_list_num **ins, t_list_num **ins2, t_list_num **list,
    t_list_num **list2, t_list_num **blist);
int							ps_select_sort(t_list_num **ins, t_list_num **list, t_list_num **blist);
int							ps_smallest(t_list_num *list);
int							ps_add_list(t_list_num **list, int num);
int							ps_size(t_list_num *list);
int							ps_not_sort(t_list_num *list);
int							ps_relative_sort(t_list_num **ins, t_list_num **list);
void						ps_print_ins(t_list_num *ins);
int							ps_convert_ins(t_list_num **ins);
int							ps_reverse_list(t_list_num **ins);
int							ps_bubble_sort(t_list_num **ins, t_list_num **list);
int							ps_copy_list(t_list_num **list2, t_list_num *list);

#endif
