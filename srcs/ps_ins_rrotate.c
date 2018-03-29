/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ins_rrotate.c                                   :+:      :+:    :+:   */
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

void	ps_ins_rrotate(t_list_num **list)
{
    t_list_num *tmplist;
    t_list_num *node;

    tmplist = NULL;
    node = NULL;
    if (*list && (*list)->next && (*list)->next->next)
	{
        node = *list;
        while ((*list)->next->next)
			*list = (*list)->next;
        tmplist = (*list)->next;
		(*list)->next = NULL;
		*list = tmplist;
		(*list)->next = node;
	}
	else
		ps_ins_switch(list);
}

void	ps_ins_rrotate_both(t_list_num **alist, t_list_num **blist)
{
    ps_ins_rrotate(alist);
    ps_ins_rrotate(blist);
}
