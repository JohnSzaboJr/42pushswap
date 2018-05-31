/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pmb.c                                           :+:      :+:    :+:   */
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

void    ps_pmb(t_list_num **list, t_list_num **blist, t_list_num **ins)
{    
    int m;

    while (ps_size(*list) >= 10)
    {
        m = ps_push_med(list, blist, ins, 1);
        while (ps_num(*blist, ps_size(*blist) - 1) >= m)
            ps_rrb(blist, ins);
    }
    while (*list)
        ps_pb(blist, list, ins);
}