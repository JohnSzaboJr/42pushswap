/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_left.c                                          :+:      :+:    :+:   */
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

int	ps_left(t_list_num *list, int p, int start)
{
	int l;
	int r;

	l = start;
	r = 0;
	ps_get_start(&list, start);
	while (list && list->num < p)
	{
		l++;
		list = list->next;
	}
	while (list && list->num != p)
		list = list->next;
	while (list)
	{
		r++;
		if (list->num < p)
			r = 0;
		list = list->next;
	}
	return (l <= r) ? 1 : 0;
}