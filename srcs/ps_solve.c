/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/23 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../checker.h"
#include "../libft/libft.h"

int	ps_solve(t_list_num **list, t_list_num **blist)
{
	t_list_num	*ins;

	ins = NULL;
	ps_normalize(list);
	if (ps_size(*list) <= 20)
	{
		ps_small_sort(&ins, list);
		ps_relative_sort(&ins, list);
		ps_select_sort(&ins, list, blist);
	}
	else
		ps_split_sort(&ins, list);
	ps_convert_ins(&ins);
	ps_print_ins(ins);
	ps_free(&ins);
	return (1);
}
