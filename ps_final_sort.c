/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_final_sort.c                                    :+:      :+:    :+:   */
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

int	ps_final_sort(t_list_num **ins, t_list_num **list, t_list_num **blist)
{
    int s;
    int pos;

    s = ps_size(*list);
    pos = ps_smallest(*list);
    //
    *blist = NULL;
    // get 1 to end
    while (pos <= s / 2 && pos > -1)
    {
        ps_ins_rotate(list);
        ps_add_list(ins, 5);
        pos--;
    }
    while (pos > s / 2 && pos < s - 1)
    {
        ps_ins_rrotate(list);
        ps_add_list(ins, 7);
        pos++;
    }
    // pb
    while (ps_proximity(*list, NULL))
    {
        ps_ins_push(blist, list);
        ps_add_list(ins, 4);
    }
    return (1);
}