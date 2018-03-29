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
int      ps_duplicates(t_list_num *list, int num);
int      make_list(int argc, char **argv, t_list_num **list);

#endif
