/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/27 13:09:58 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../checker.h"
#include "../libft/libft.h"
//
#include <stdio.h>

int	ps_ins_switch(t_list_num **list, int tmp)
{
	if ((*list) && (*list)->next)
	{
		(*list)->num = (*list)->next->num;
		(*list)->next->num = tmp;
	}
	return (1);
}

int	ps_ins_push(t_list_num **dstlist, t_list_num **srclist)
{
	t_list_num *second;
	t_list_num *tmp;

	second = NULL;
	tmp = *dstlist;
	if (*srclist)
	{
		second = (*srclist)->next;
		*dstlist = *srclist;
		(*dstlist)->next = tmp;
		*srclist = second;
	}
	return (1);
}

int     ps_ins_rotate(t_list_num **list)
{
  	t_list_num *tmplist;
	t_list_num *node;
	
	tmplist = NULL;
	node = NULL;
	if (*list && (*list)->next)
	  {
	    tmplist = *list;
	    node = (*list)->next;
	    while ((*list)->next)
		*list = (*list)->next;
	    (*list)->next = tmplist;
	    tmplist->next = NULL;
	    *list = node;
	  }
	return (1);
}

int     ps_ins_rrotate(t_list_num **list, int tmp)
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
		ps_ins_switch(list, tmp);
    return (1);
}

int	ps_instruction(t_list_num **list, t_list_num **blist, char *line)
{
	int	tmp;
	int btmp;

	tmp = (*list)->num;
	btmp = 0;
	if (*blist)
		btmp = (*list)->num;
	*blist = NULL;
	// check if it is a valid instruction
	if (!(ft_strcmp(line, "sa")) && !ps_ins_switch(list, tmp))
		return (throw_error());
	if (!(ft_strcmp(line, "sb")) && !ps_ins_switch(blist, btmp))
		return (throw_error());
	if (!(ft_strcmp(line, "ss")) && !ps_ins_switch(list,tmp) &&
	    !ps_ins_switch(blist, btmp))
		return (throw_error());
	if (!(ft_strcmp(line, "pa")) && !ps_ins_push(list, blist))
		return (throw_error());
	if (!(ft_strcmp(line, "pb")) && !ps_ins_push(blist, list))
		return (throw_error());
	if (!(ft_strcmp(line, "ra")) && !ps_ins_rotate(list))
		return (throw_error());
	if (!(ft_strcmp(line, "rb")) && !ps_ins_rotate(blist))
          return (throw_error());
	if (!(ft_strcmp(line, "rr")) && !ps_ins_rotate(list) &&
	!ps_ins_rotate(blist))
          return (throw_error());
    if (!(ft_strcmp(line, "rra")) && !ps_ins_rrotate(list, tmp))
		return (throw_error());
    if (!(ft_strcmp(line, "rrb")) && !ps_ins_rrotate(blist, btmp))
        return (throw_error());
    if (!(ft_strcmp(line, "rrr")) && !ps_ins_rrotate(list, tmp)
	&& !ps_ins_rrotate(blist, btmp))
        return (throw_error());
	return (1);
}
