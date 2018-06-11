/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_normalize.c                                     :+:      :+:    :+:   */
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

void	ps_normaloop(t_list_num **list, t_list_num *node, int s, int i)
{
	while (s > 0)
	{
		while ((*list)->num != ps_largest_num(*list))
			(*list) = (*list)->next;
		(*list)->num = i;
		i--;
		s--;
		*list = node;
	}
}

void	ps_normalize(t_list_num **list)
{
	t_list_num	*node;
	int			i;
	int			s;

	node = *list;
	i = ps_num(*list, ps_smallest(*list)) - 1;
	i = i > 0 ? 0 : i;
	s = ps_size(*list);
	ps_normaloop(list, node, s, i);
	s = ps_size(*list);
	i = 1;
	while (s > 0)
	{
		while ((*list)->num != ps_num(*list, ps_smallest(*list)))
			(*list) = (*list)->next;
		(*list)->num = i;
		i++;
		s--;
		*list = node;
	}
}
