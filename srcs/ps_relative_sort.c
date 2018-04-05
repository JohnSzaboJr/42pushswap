/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_relative_sort.c                                 :+:      :+:    :+:   */
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

int	ps_relative_sort(t_list_num **ins, t_list_num **list)
{
t_list_num *lasta;
int size;
int pos;

lasta = *list;
size = ps_size(*list);
pos = ps_smallest(*list);
while (lasta->next)
	lasta = lasta->next;
if (ps_not_sort(*list) == 1 && lasta->num < (*list)->num)
	{
	while (pos <= size / 2 && pos > 0)
		{
			ps_ins_rotate(list);
			ps_add_list(ins, 5);
			pos--;
		}
		while (pos > size / 2 && pos < size)
		{
			ps_ins_rrotate(list);
			ps_add_list(ins, 7);
			pos++;
		}
	}
	return (1);
}