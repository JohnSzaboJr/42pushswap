/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fsort.c                                         :+:      :+:    :+:   */
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

int		ps_distance3(t_list_num *blist, int n)
{
	int p;
	int	s;

	s = ps_size(blist);
	p = ps_position(blist, n);
	return (p < s / 2) ? (p) : (s - p); 
}

void	ps_fsort(t_list_num **list, t_list_num **blist, t_list_num **ins)
{
	int a;
	int b;
	int c;
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
		c = 0;
		if (a <= b)
		{
			ps_rotate_into_place2(list, 0, l + 1, ins);
			if ((ps_distance3(*blist, l - 1)) <= a)
			{
				c = 1;
				ps_rotate_into_place(blist, 0, l - 1, ins);
				ps_pa(list, blist, ins);
			}
			ps_rotate_into_place(blist, 0, l, ins);
		}
		else
		{
			ps_rotate_into_place2(list, ps_size(*list) - 1, s - 1, ins);
			// if ((ps_distance3(*blist, s + 2)) <= b / 2)
			// {
			// 	ps_rotate_into_place(blist, 0, s + 2, ins);
			// 	ps_pa(list, blist, ins);
			// }
			if ((ps_distance3(*blist, s + 1)) <= b)
			{
				ps_rotate_into_place(blist, 0, s + 1, ins);
				ps_pa(list, blist, ins);
			}
			ps_rotate_into_place(blist, 0, s, ins);
		}
		ps_pa(list, blist, ins);
		if (c)
			ps_sa(list, ins);
	}
	ps_rotate_into_place2(list, 0, 1, ins);
}
