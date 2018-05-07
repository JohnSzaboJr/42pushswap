/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_proximity.c                                     :+:      :+:    :+:   */
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

int	ps_proximity(t_list_num *list, t_list_num *blist)
{
    t_list_num  *nodea;
    t_list_num  *nodeb;
    int         ans;
    int         i;
    int         onepos;

    nodea = list;
    nodeb = blist;
    onepos = 0;
    ans = 0;
    i = -1;
    while (blist && blist->num != 1)
    {
        blist = blist->next;
        onepos--;
    }
    if (blist)
        onepos--;
    while (list && list->num != 1)
    {
        list = list->next;
        if (onepos >= 0)
            onepos++;
    }
    list = nodea;
    blist = nodeb;
    while (blist)
    {
        ans = i > (onepos + (blist->num) - 1) ?
        ans + (i - (onepos + (blist->num) - 1)) :
        ans + ((onepos + (blist->num) - 1) - i);
        blist = blist->next;
        i--;
    }
    i = 0;
    while (list)
    {
        ans = i > (onepos + (list->num) - 1) ?
        ans + (i - (onepos + (list->num) - 1)) :
        ans + ((onepos + (list->num) - 1) - i);
        list = list->next;
        i++;
    }
    return (ans);
}