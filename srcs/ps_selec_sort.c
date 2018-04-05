/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_select_sort.c                                   :+:      :+:    :+:   */
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

int	ps_select_sort(t_list_num **ins, t_list_num **list, t_list_num **blist)
{
	int pos;
	int size;

	while (*list && ps_not_sort(*list))
	{
		size = ps_size(*list);
		pos = ps_smallest(*list);
		if (pos == 1)
		{
			ps_ins_switch(list);
			ps_add_list(ins, 1);
			pos = 0;
		}
		while (pos <= size / 2 && pos > 0)
		{
			ps_ins_rotate(list);
			ps_add_list(ins, 5);
			pos--;
		}
		while (pos > size / 2 && pos < size)
		{
			ps_ins_rrotate(list);
			ps_add_list(ins, 7);
			pos++;
		}
		if (ps_not_sort(*list))
		{
			ps_ins_push(blist, list);
			ps_add_list(ins, 4);
			ps_relative_sort(ins, list);
		}
	}
	while (*blist)
	{
		ps_ins_push(list, blist);
		ps_add_list(ins, 3);	
	}
	return (1);
}