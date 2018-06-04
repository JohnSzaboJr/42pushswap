/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.c                                         :+:      :+:    :+:   */
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

int	ps_solve(int argc, char **argv, t_list_num **blist)
{
    t_list_num *list;
    t_list_num *list2;
    t_list_num *ins;

    list = NULL;
    list2 = NULL;
    ins = NULL;
    make_list(argc, argv, &list);
    make_list(argc, argv, &list2);
    ps_relative_sort(&ins, &list2);
    ps_select_sort(&ins, &list2, blist);
    if (ps_size(list) > 20)
    {
        ins = NULL;
        ps_convert_order(&list, list2);
        ps_split_sort(&ins, &list);
    }
    ps_convert_ins(&ins);
    ps_print_ins(ins);
    // printf("original size: %d\n", ps_size(ins));
    // printf("optimized size: %d\n", ps_size(ins) - ps_null(ins));
	// ps_print_list(list);
	return (1);
}