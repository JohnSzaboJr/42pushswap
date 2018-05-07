/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_count_error.c                                   :+:      :+:    :+:   */
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

int	ps_count_error(t_list_num *list, int num, int end_num)
{
	int	error;

	error = 0;
	while (list && list->num != num)
	{
		if (list->num > num)
			error++;
		list = list->next;
	}
	while (list && list->num != end_num)
	{
		if (list->num < num)
			error++;
		list = list->next;
	}
	return (error);
}