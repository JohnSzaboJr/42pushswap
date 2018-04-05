/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_list.c                                  :+:      :+:    :+:   */
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

int	ps_reverse_list(t_list_num **list)
{
    t_list_num *next;
    t_list_num *tmp;
    t_list_num *node;

    next = NULL;
    tmp = NULL;
    node = *list;
    while (node->next)
        node = node->next;
    while (*list)
    {
        next = (*list)->next;
        (*list)->next = tmp;
        tmp = *list;
        *list = next;
    }
    *list = node;
    return (1);
}