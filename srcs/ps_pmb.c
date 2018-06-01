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
    int i;

    i = 0;
    while (ps_size(*list) >= 10)
    {
        m = ps_push_med(list, blist, ins, 1);
        while (ps_num(*blist, ps_size(*blist) - 1) >= m)
        {
            ps_rrb(blist, ins);
            i++;
        }
    }
    // if (i > 20)
    //     resplit();
    
    // for the first transfer: check if it is larger than 40, and if yes, transfer back half from each end,
    // and splitting them, transfer them back.

    // get m2 between m and largest
    // get m3 between m2 and largest
    // transfer the larger ones to a
    // transfer back the ones larger of m3 to back, smaller to front (all larger than m2)
    // rotate the ones larger than m3 to front.

    while (*list)
        ps_pb(blist, list, ins);
}