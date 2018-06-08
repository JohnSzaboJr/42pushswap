/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_g_s.c                                           :+:      :+:    :+:   */
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

void	ps_g_s(t_list_num **list, t_list_num **blist, t_list_num **ins, int b)
{
	int	s;

	s = ps_num(*blist, ps_smallest(*blist));
	ps_rotate_into_place2(list, ps_size(*list) - 1, s - 1, ins);
	if (ps_distance3(*blist, s + 1) != -1 &&
	ps_distance3(*blist, s + 1) <= b)
	{
		if (ps_distance3(*blist, s + 2) != -1 &&
		(ps_distance3(*blist, s + 2)) <= b / 2)
		{
			ps_rotate_into_place(blist, 0, s + 2, ins);
			ps_pa(list, blist, ins);
		}
		ps_rotate_into_place(blist, 0, s + 1, ins);
		ps_pa(list, blist, ins);
	}
	ps_rotate_into_place(blist, 0, s, ins);
	ps_pa(list, blist, ins);
}
