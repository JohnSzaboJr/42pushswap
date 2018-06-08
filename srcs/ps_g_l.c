/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_g_l.c                                           :+:      :+:    :+:   */
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

void	ps_g_l(t_list_num **list, t_list_num **blist, t_list_num **ins, int a)
{
	int	l;
	int	c;

	c = 0;
	l = ps_largest_num(*blist);
	ps_rotate_into_place2(list, 0, l + 1, ins);
	if (ps_distance3(*blist, l - 1) != -1 &&
	ps_distance3(*blist, l - 1) <= a)
	{
		c = 1;
		ps_rotate_into_place(blist, 0, l - 1, ins);
		ps_pa(list, blist, ins);
	}
	ps_rotate_into_place(blist, 0, l, ins);
	ps_pa(list, blist, ins);
	if (c)
	{
		ps_sa(list, ins);
		if (*blist && (*blist)->next &&
		(*blist)->num + 1 == (*blist)->next->num)
			ps_sb(blist, ins);
	}
}
