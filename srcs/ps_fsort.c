/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fsort.c                                   :+:      :+:    :+:   */
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

void     ps_fsort(t_list_num **list, t_list_num **blist, t_list_num **ins)
{
	int a;
	int b;
	int s;
	int l;

	ps_rotate_into_place(blist, 0, ps_largest_num(*blist), ins);
	ps_pa(list, blist, ins);
	while (*blist)
	{
		l = ps_largest_num(*blist);
		s = ps_num(*blist, ps_smallest(*blist));
		a = ps_distance1(*list, *blist);
		b = ps_distance2(*list, *blist);
		if (a <= b)
		{
			ps_rotate_into_place(blist, 0, l, ins);
			ps_rotate_into_place2(list, 0, l + 1, ins);
		}
		else
		{
			ps_rotate_into_place(blist, 0, s, ins);
			ps_rotate_into_place2(list, ps_size(*list) - 1, s - 1, ins);
		}
		ps_pa(list, blist, ins);
	}
	ps_rotate_into_place2(list, 0, 1, ins);
}