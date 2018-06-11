/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_ins.c                                     :+:      :+:    :+:   */
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

void	ps_print_ins(t_list_num *ins)
{
	const char *instructions[] = {"sa\n", "sb\n", "pa\n", "pb\n", "ra\n",
								"rb\n", "rra\n", "rrb\n", "ss\n", "rr\n",
								"rrr\n", ""};

	while (ins)
	{
		ft_putstr(instructions[ins->num - 1]);
		ins = ins->next;
	}
}
