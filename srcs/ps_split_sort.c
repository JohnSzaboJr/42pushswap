/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split_sort.c                                    :+:      :+:    :+:   */
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

void     ps_split_sort(t_list_num **ins, t_list_num **list)
{
	t_list_num *blist;

	blist = NULL;
	ps_push_med(list, &blist, ins, 0);
	ps_pmb(list, &blist, ins);
	if (ps_size(blist) > 200)
	{
		ps_endsplit(list, &blist, ins);
		ps_pmb2(list, &blist, ins);
	}
	ps_final_ssort(list, &blist, ins);
}