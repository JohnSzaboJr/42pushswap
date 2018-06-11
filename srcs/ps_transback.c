/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_transback.c                                     :+:      :+:    :+:   */
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

void	ps_transback(t_list_num **list, t_list_num **blist, t_list_num **ins)
{
	int	m;
	int	m2;

	m = ps_median(*blist, 0, ps_size(*blist) - 1);
	m2 = (m + ps_largest_num(*blist)) / 2;
	while ((*blist)->num >= m)
	{
		if ((*blist)->num >= m2)
			ps_pa(list, blist, ins);
		else
			ps_rb(blist, ins);
	}
	while (ps_num(*blist, ps_size(*blist) - 1) >= m)
		ps_rrb(blist, ins);
}
