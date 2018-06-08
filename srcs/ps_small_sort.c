/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_sort.c                                    :+:      :+:    :+:   */
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

void    ps_small_sort(t_list_num **ins, t_list_num **list)
{
	while (ps_not_sort(*list) && ps_size(*list) <= 3)
	{
		if ((*list) && (*list)->next && (*list)->num - 1 == (*list)->next->num)
			ps_sa(list, ins);
		if (ps_smallest(*list) == ps_size(*list) - 1)
			ps_rra(list, ins);
		if (ps_smallest(*list) == ps_size(*list) - 2)
			ps_ra(list, ins); 
	}
}
