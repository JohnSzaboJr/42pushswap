/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_final_ssort.c                                   :+:      :+:    :+:   */
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

// void     ps_final_ssort(t_list_num **list, t_list_num **blist, t_list_num **ins)
// {
//     while (*blist)
//     {
//         ps_rotate_into_place(blist, 0, ps_largest_num(*blist), ins);
//         ps_pa(list, blist, ins);
//     }
// }


void	ps_rotate_n2(t_list_num **list, int	n, t_list_num **ins)
{
	while (n)
	{
		ps_ins_rotate(list);
		ps_add_list(ins, 5);
		n--;
	}
}

void	ps_rrotate_n2(t_list_num **list, int	n, t_list_num **ins)
{
	while (n)
	{
		ps_ins_rrotate(list);
		ps_add_list(ins, 7);
		n--;
	}
}

void	ps_rotate_into_place2
	(t_list_num **list, int end, int last, t_list_num **ins)
{
	int			pos;

	pos = ps_position(*list, last);
	if (pos == ps_size(*list))
		return ;
	if (pos < end && (end - pos) < (ps_size(*list) / 2))
		ps_rrotate_n2(list, end - pos, ins);
	else if (pos < end && (end - pos) >= (ps_size(*list) / 2))
		ps_rotate_n2(list, ps_size(*list) - (end - pos), ins);
	else if (pos > end && (pos - end) < (ps_size(*list) / 2))
		ps_rotate_n2(list, pos - end, ins);
	else if (pos > end && (pos - end) >= (ps_size(*list) / 2))
		ps_rrotate_n2(list, ps_size(*list) - (pos - end), ins);
}

void     ps_final_ssort(t_list_num **list, t_list_num **blist, t_list_num **ins)
{
    int a;
    int b;

    ps_rotate_into_place(blist, 0, ps_largest_num(*blist), ins);
    ps_pa(list, blist, ins);

    while (*blist)
    {
        a = ps_position(*blist, ps_largest_num(*blist)) <
        ps_size(*blist) / 2 ? ps_position(*blist, ps_largest_num(*blist)) :
        ps_size(*blist) - ps_position(*blist, ps_largest_num(*blist));
        a = ps_position(*list, ps_largest_num(*blist) + 1) <
        ps_size(*list) / 2 ? ps_position(*list, ps_largest_num(*blist) + 1) + a :
        ps_size(*list) - ps_position(*list, ps_largest_num(*blist) + 1) + a;
        b = ps_smallest(*blist) < ps_size(*blist) / 2 ?
        ps_smallest(*blist) : ps_size(*blist) - ps_smallest(*blist);
        b = ps_position(*list, ps_num(*blist, ps_smallest(*blist)) - 1) < ps_size(*list) / 2 ? ps_position(*list, ps_num(*blist, ps_smallest(*blist)) - 1) + b :
        ps_size(*list) - ps_position(*list, ps_num(*blist, ps_smallest(*blist)) - 1) + b;
        if (a <= b)
        {
            ps_rotate_into_place(blist, 0, ps_largest_num(*blist), ins);
            ps_rotate_into_place2(list, 0, ps_largest_num(*blist) + 1, ins);
            ps_pa(list, blist, ins);
        }
        else
        {
            ps_rotate_into_place(blist, 0, ps_num(*blist, ps_smallest(*blist)), ins);
            ps_rotate_into_place2(list, ps_size(*list) - 1, ps_num(*blist, ps_smallest(*blist)) - 1, ins);
            ps_pa(list, blist, ins);
        }
    }
    ps_rotate_into_place2(list, 0, 1, ins);
}