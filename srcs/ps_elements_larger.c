/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pps_elements_larger.c                              :+:      :+:    :+:   */
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

int	ps_elements_larger(t_list_num *list, int n)
{
	while (list)
	{
		if (list->num < n)
			return (0);
		list = list->next;
	}
	return (1);
}
