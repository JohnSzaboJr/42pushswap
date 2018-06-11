/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_med.c                                      :+:      :+:    :+:   */
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

int	ps_push_med(t_list_num **src, t_list_num **trg, t_list_num **ins, int s)
{
	int m;
	int m2;

	m = ps_median(*src, 0, ps_size(*src) - 1);
	m2 = (m + ps_num(*src, ps_smallest(*src))) / 2;
	while (!ps_elements_larger(*src, m))
	{
		if ((*src) && (*src)->next && (*src)->num - 1 == (*src)->next->num)
			ps_sa(src, ins);
		if ((*src)->num < m)
		{
			ps_pb(trg, src, ins);
			if (((*trg)->num < m2 && !s) || ((*trg)->num >= m2 && s))
				ps_rb(trg, ins);
		}
		else
			ps_ra(src, ins);
	}
	return (m2);
}
