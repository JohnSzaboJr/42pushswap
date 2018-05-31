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
//
#include <stdio.h>

int     ps_split_sort(t_list_num **ins, t_list_num **list)
{
    int m;
    int m2;
    int m3;
    t_list_num *blist;

	blist = NULL;
    ps_push_med(list, &blist, ins, 0);
    ps_pmb(list, &blist, ins);
    m2 = (ps_median(blist, 0, ps_size(blist) - 1) + ps_num(blist, ps_smallest(blist))) / 2;
    m3 = (m2 + ps_num(blist, ps_smallest(blist))) / 2;
    while (ps_num(blist, ps_size(blist) - 1) < m2)
    {
        ps_rrb(&blist, ins);
        if (blist->num < m3)
            ps_pa(list, &blist, ins);
    }
    while (blist->num < m2)
        ps_rb(&blist, ins);
    while (ps_size(*list) >= 10)
    {
        m = ps_push_med2(list, &blist, ins);
        while (ps_num(blist, ps_size(blist) - 1) < m)
            ps_rb(&blist, ins);
    }
    while (*list)
        ps_pb(&blist, list, ins);
     while (blist->num < m2)
        ps_rb(&blist, ins);
    while (blist)
    {
        ps_rotate_into_place(&blist, 0, ps_largest_num(blist), ins);
        ps_pa(list, &blist, ins);
    }  
    return (1);
}