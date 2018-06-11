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

void	ps_select_sort(t_list_num **ins, t_list_num **list, t_list_num **blist)
{
	int	size;

	while (*list && ps_not_sort(*list))
	{
		size = ps_size(*list);
		if (size <= 3)
		{
			ps_small_sort(ins, list);
			break ;
		}
		if (ps_smallest(*list) == 1)
			ps_sa(list, ins);
		else
			ps_rotate_into_place2(list, 0,
			ps_num(*list, ps_smallest(*list)), ins);
		if (ps_not_sort(*list))
			ps_pb(blist, list, ins);
	}
	while (*blist)
	{
		ps_ins_push(list, blist);
		ps_add_list(ins, 3);	
	}
}
