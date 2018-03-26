/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/26 16:19:36 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../checker.h"
#include "../libft/libft.h"

void	ps_ins_switch(t_list_num **list, int tmp)
{
	if ((*list) && (*list)->next)
	{
		(*list)->num = (*list)->next->num;
		(*list)->next->num = tmp;
	}

}

int	ps_ins_push(t_list_num **dstlist, t_list_num **srclist, int tmp)
{
	t_list_num *new;
	t_list_num **tmplist;
	t_list_num *tmpsrclist;

	new = NULL;
	tmplist = dstlist;
	tmpsrclist = *srclist;
	if (*srclist)
	{
		if (!(new = (t_list_num *)malloc(sizeof(*new))))
            return (throw_error());
		new->num = tmp;
		new->next = *tmplist;
		*dstlist = new;
		*srclist = (*srclist)->next;
		free(tmpsrclist);
	}
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
	if (!(ft_strcmp(line, "sa")))
		ps_ins_switch(list, tmp);
    else if (!(ft_strcmp(line, "sb")))
		ps_ins_switch(blist, btmp);
	else if (!(ft_strcmp(line, "ss")))
	{
		ps_ins_switch(list,tmp);
        ps_ins_switch(blist, btmp);
	}
	else if (!(ft_strcmp(line, "pa")))
        ps_ins_push(list, blist, btmp);
    else if (!(ft_strcmp(line, "pb")))
        ps_ins_push(blist, list, tmp);
	else
		return (throw_error());
	return (1);
}
