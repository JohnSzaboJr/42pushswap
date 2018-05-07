/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_copy_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:59:32 by jszabo            #+#    #+#             */
/*   Updated: 2018/04/05 12:59:33 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../checker.h"
#include "../libft/libft.h"

int	ps_copy_list(t_list_num **list2, t_list_num *list)
{
    t_list_num *tmp;

    tmp = NULL;
    *list2 = NULL;
    while (list)
    {
        if (!(tmp = (t_list_num *)malloc(sizeof(*tmp))))
	        return (throw_error());
        tmp->num = list->num;
        tmp->next = *list2;
        *list2 = tmp;
        list = list->next;
    }
    ps_reverse_list(list2);
    return (1);
}