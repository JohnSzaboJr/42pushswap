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
//
#include <stdio.h>

int ps_null(t_list_num *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (list->num == 12)
			i++;
		list = list->next;
	}
	return (i);
}

int	ps_solve(t_list_num **list, t_list_num **blist)
{
    t_list_num *ins;

    ins = NULL;
    if (ps_size(*list) <= 20)
    {
        ps_small_sort(&ins, list);
        ps_relative_sort(&ins, list);
        ps_select_sort(&ins, list, blist);
    }
    else
    {
        ps_normalize(list);
        ps_split_sort(&ins, list);
    }
    ps_convert_ins(&ins);
    ps_print_ins(ins);
    // printf("original size: %d\n", ps_size(ins));
    // printf("optimized size: %d\n", ps_size(ins) - ps_null(ins));
	// ps_print_list(list);
	return (1);
}