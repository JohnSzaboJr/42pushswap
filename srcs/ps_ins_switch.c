/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ins_switch.c                                    :+:      :+:    :+:   */
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

void	ps_ins_switch(t_list_num **list)
{
	int tmp;

	tmp = 0;
	if ((*list) && (*list)->next)
	{
		tmp = (*list)->num;
		(*list)->num = (*list)->next->num;
		(*list)->next->num = tmp;
	}
}

void	ps_ins_switch_both(t_list_num **alist, t_list_num **blist)
{
	ps_ins_switch(alist);
	ps_ins_switch(blist);
}
