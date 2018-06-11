/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_median.c                                        :+:      :+:    :+:   */
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

int	ps_median(t_list_num *list, int start, int end)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i != start)
	{
		list = list->next;
		i++;
	}
	while (list && i != end)
	{
		sum = sum + list->num;
		list = list->next;
		i++;
	}
	if (list)
		sum = sum + list->num;
	return (sum / (end + 1 - start));
}
