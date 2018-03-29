/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_sort.c                                    :+:      :+:    :+:   */
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
#include <stdio.h>

int	ps_check_sort(t_list_num *list, int n)
{
    int i;

    i = 1;
    while (list->next)
    {
        if (list->num > list->next->num)
        {
            ft_putstr("KO\n");
            return (0);
        }
        list = list->next;
        i++;
    }
    if (i != n)
    {
        ft_putstr("KO\n");
        return (0);
    }
    ft_putstr("OK\n");
    return (0);
}
