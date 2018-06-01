/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_transsplit.c                                    :+:      :+:    :+:   */
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

void     ps_transsplit(t_list_num **list, t_list_num **blist, t_list_num **ins)
{
    int m;
    int m2;
    int l;
    int s;

    l = ps_num(*list, ps_smallest(*list));
    s = ps_size(*list) + 10;
    m = ps_median(*blist, 0, ps_size(*blist) - 1);
    m2 = (m + ps_largest_num(*blist)) / 2;
    while ((*blist)->num >= m)
    {
        if ((*blist)->num >= m2)
            ps_pa(list, blist, ins);
        else
            ps_rb(blist, ins);
    }
    while (ps_num(*blist, ps_size(*blist) - 1) >= m)
        ps_rrb(blist, ins);
    while (ps_size(*list) >= s)
    {
        m = (l - 1 + ps_num(*list, ps_smallest(*list))) / 2;
        m2 = (m + l - 1) / 2;
        while ((*list)->num < l)
        {
            if ((*list)->num < m)
                ps_pb(blist, list, ins);
            else
                ps_ra(list, ins);
            if ((*blist)->num >= m2)
                ps_rb(blist, ins);
        }
        while (ps_num(*blist, ps_size(*blist) - 1) >= m2)
            ps_rrb(blist, ins);
        while (ps_num(*list, ps_size(*list) - 1) < l)
            ps_rra(list, ins);
    }
    while (ps_size(*list) > s - 10)
        ps_pb(blist, list, ins);
}