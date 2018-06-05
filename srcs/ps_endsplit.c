/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_endsplit.c                                      :+:      :+:    :+:   */
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

void	ps_endsplit(t_list_num **list, t_list_num **blist, t_list_num **ins)
{
	int m;
	int m2;

	m = (ps_median(*blist, 0, ps_size(*blist) - 1)
		+ ps_num(*blist, ps_smallest(*blist))) / 2;
	m2 = (m + ps_num(*blist, ps_smallest(*blist))) / 2;
	while (ps_num(*blist, ps_size(*blist) - 1) < m)
	{
		ps_rrb(blist, ins);
		if ((*blist)->num < m2)
			ps_pa(list, blist, ins);
	}
	while ((*blist)->num < m)
		ps_rb(blist, ins);
}
