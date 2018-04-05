/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smallest.c                                      :+:      :+:    :+:   */
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

int	ps_smallest(t_list_num *list)
{
    int smallest;
    int pos;
    int sm_pos;

    pos = 0;
    sm_pos = 0;
    if (!list)
        return (-1);
    smallest = list->num;
    while (list)
    {
        if (list->num <= smallest)
        {
            smallest = list->num;
            sm_pos = pos;
        }
        list = list->next;
        pos++;
    }
    return (sm_pos);
}