/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_pivot.c                                    :+:      :+:    :+:   */
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

int ps_find_pivot(t_list_num *list, int start, int end, int *p)
{
	int			end_num;
	int			error_prev;
	int			error_new;
	t_list_num	*node;

	end_num = (ps_size(list) - 1 == end) ? -1 : ps_num(list, end + 1);
	error_prev = ps_size(list);
	error_new = 0;
	ps_get_start(&list, start);
	node = list;
	while (list && list->num != end_num)
	{
		if (!(error_new = ps_count_error(node, list->num, end_num)))
		{
			*p = list->num;
			return (error_new);
		}
		if (error_new < error_prev)
		{
			*p = list->num;
			error_prev = error_new;
		}
		list = list->next;
	}
	return (error_prev);
}