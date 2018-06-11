/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_resplit2.c                                      :+:      :+:    :+:   */
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

void	ps_resplit2(t_list_num **list, t_list_num **blist,
	t_list_num **ins, int m)
{
	int m2;
	int m3;
	int l;

	l = ps_largest_num(*list);
	m2 = (m + ps_num(*blist, ps_smallest(*blist))) / 2;
	while ((*blist)->num < m)
	{
		if ((*blist)->num < m2)
			ps_pa(list, blist, ins);
		else
			ps_rb(blist, ins);
	}
	m3 = (m2 + l) / 2;
	while ((*list)->num > l)
	{
		ps_pb(blist, list, ins);
		if ((*blist)->num >= m3)
			ps_rb(blist, ins);
	}
}
