/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_duplicates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 10:53:26 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/29 10:57:37 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../checker.h"
#include "../libft/libft.h"

int	ps_duplicates(t_list_num *list, int num)
{
	list = list->next;
	while (list)
	{
		if (list->num == num)
			return (1);
		list = list->next;
	}
	return (0);
}
