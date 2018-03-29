/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_throw_rotate.c                                  :+:      :+:    :+:   */
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

void     ps_ins_rotate(t_list_num **list)
{
  	t_list_num *tmplist;
	t_list_num *node;
	
	tmplist = NULL;
	node = NULL;
    if (*list && (*list)->next)
    {
        node = *list;
        *list = (*list)->next;
        tmplist = *list;
        while (tmplist->next)
            tmplist = tmplist->next;
        tmplist->next = node;
        node->next = NULL;
    }
}

void    ps_ins_rotate_both(t_list_num **alist, t_list_num **blist)
{
    ps_ins_rotate(alist);
    ps_ins_rotate(blist);
}
