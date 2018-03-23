/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/23 16:10:03 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../checker.h"
#include "../libft/libft.h"

int	ps_instruction(t_list_num **list, t_list_num **blist, char *line)
{
	int	tmp;

	tmp = (*list)->num;
	*blist = NULL;
	if (!(ft_strcmp(line, "sa")))
	{
		if ((*list)->next)
		{
			(*list)->num = (*list)->next->num;
			(*list)->next->num = tmp;
		}
	}
	else
		return (throw_error());
	return (1);
}
