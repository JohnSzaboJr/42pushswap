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
//
#include <stdio.h>

int	ps_copy_list(t_list_num **list2, t_list_num *list)
{
    t_list_num *node;
    t_list_num *tmp;

    tmp = NULL;
    if (list && !(*list2 = (t_list_num *)malloc(sizeof(*node))))
        return (throw_error());
    node = *list2;
    while (list)
    {
        (*list2)->num = list->num;
        if (list->next && !(tmp = (t_list_num *)malloc(sizeof(*tmp))))
            return (throw_error());
        (*list2)->next = tmp;
        list = list->next;
    }
    (*list2)->next = NULL;
    *list2 = node;
    printf("list2->num: %d\n", (*list2)->num);
    printf("list2->next->num: %d\n", (*list2)->next->num);
    return (1);
}