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
	t_list_num	*node;

	end_num = (ps_size(list) - 1 == end) ? -1 : ps_num(list, end + 1);
	*p = ps_median(list, start, end);
	ps_get_start(&list, start);
	node = list;
	return (ps_count_error(node, *p, end_num));
}