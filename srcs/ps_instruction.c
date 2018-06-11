/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/29 13:32:19 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../checker.h"
#include "../libft/libft.h"

int	ps_instruction(t_list_num **list, t_list_num **blist, char *line)
{
	if (!ft_strcmp(line, "sa"))
		ps_ins_switch(list);
	else if (!ft_strcmp(line, "sb"))
		ps_ins_switch(blist);
	else if (!ft_strcmp(line, "ss"))
		ps_ins_switch_both(list, blist);
	else if (!ft_strcmp(line, "pa"))
		ps_ins_push(list, blist);
	else if (!(ft_strcmp(line, "pb")))
		ps_ins_push(blist, list);
	else if (!ft_strcmp(line, "ra"))
		ps_ins_rotate(list);
	else if (!ft_strcmp(line, "rb"))
		ps_ins_rotate(blist);
	else if (!ft_strcmp(line, "rr"))
		ps_ins_rotate_both(list, blist);
	else if (!ft_strcmp(line, "rra"))
		ps_ins_rrotate(list);
	else if (!ft_strcmp(line, "rrb"))
		ps_ins_rrotate(blist);
	else if (!ft_strcmp(line, "rrr"))
		ps_ins_rrotate_both(list, blist);
	else
		return (throw_error());
	return (1);
}
