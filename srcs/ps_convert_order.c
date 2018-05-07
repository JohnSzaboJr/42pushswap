/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_convert_order.c                                 :+:      :+:    :+:   */
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
//
#include <stdio.h>

int	ps_convert_order(t_list_num **dstlist, t_list_num *srclist)
{
    t_list_num  *node;
    t_list_num  *list;
    t_list_num  *tmp;
    int         i;

    i = 1;
    node = *dstlist;
    list = NULL;
    tmp = NULL;
    while (*dstlist)
    {
        if (!(tmp = (t_list_num *)malloc(sizeof(*tmp))))
	        return (throw_error());
        tmp->num = 0;
        tmp->next = list;
        list = tmp;
        *dstlist = (*dstlist)->next;
    }
    *dstlist = node;
    tmp = list;
    while (srclist)
    {
        while ((*dstlist)->num != srclist->num)
        {
            *dstlist = (*dstlist)->next;
            list = list->next;
        }
        list->num = i; 
        *dstlist = node;
        list = tmp;
        srclist = srclist->next;
        i++;
    }
    ps_free(dstlist);
    *dstlist = list;
    return (1);
}