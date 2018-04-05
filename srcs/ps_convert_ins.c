/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_convert_ins.c                                   :+:      :+:    :+:   */
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

int	ps_convert_ins(t_list_num **ins)
{
    t_list_num *tmp;

    tmp = *ins;
    while (tmp && tmp->next)
    {
        if ((tmp->num == 1 && tmp->next->num == 2) ||
            (tmp->num == 2 && tmp->next->num == 1))
            {
            tmp->num = 9;
            tmp->next->num = 12;
            }
        else if ((tmp->num == 5 && tmp->next->num == 6) ||
            (tmp->num == 6 && tmp->next->num == 5))
            {
            tmp->num = 10;
            tmp->next->num = 12;
            }
        else if ((tmp->num == 7 && tmp->next->num == 8) ||
            (tmp->num == 8 && tmp->next->num == 7))
            {
            tmp->num = 11;
            tmp->next->num = 12;
            }
    tmp = tmp->next;
    }
    ps_reverse_list(ins);
    return (1);
}