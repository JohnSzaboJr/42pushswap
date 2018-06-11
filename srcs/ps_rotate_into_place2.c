/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_into_place2.c                            :+:      :+:    :+:   */
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
