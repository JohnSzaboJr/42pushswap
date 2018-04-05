/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:08:04 by jszabo            #+#    #+#             */
/*   Updated: 2018/04/05 12:08:06 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../checker.h"
#include "../libft/libft.h"

int	ps_bubble_sort(t_list_num **ins, t_list_num **list)
{
    int i;
    int size;

    i = 1;
    size = ps_size(*list);
    while (*list && ps_not_sort(*list))
    {
        if ((*list)->num > (*list)->next->num && (i % size))
        {
            ps_ins_switch(list);
            ps_add_list(ins, 1);
        }
        ps_ins_rotate(list);
	    ps_add_list(ins, 5);
        i++;
    }
    return (1);
}