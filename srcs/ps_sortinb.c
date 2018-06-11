/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sortinb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:13:13 by jszabo            #+#    #+#             */
/*   Updated: 2018/06/01 14:13:14 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../checker.h"
#include "../libft/libft.h"

int	ps_sortinb(t_list_num **list, t_list_num **blist, t_list_num **ins,
	int l)
{
	int	m;
	int	m2;

	m = (l - 1 + ps_num(*list, ps_smallest(*list))) / 2;
	m2 = (m + l - 1) / 2;
	while ((*list)->num < l)
	{
		if ((*list)->num < m)
			ps_pb(blist, list, ins);
		else
			ps_ra(list, ins);
		if ((*blist)->num >= m2)
			ps_rb(blist, ins);
	}
	return (m2);
}
