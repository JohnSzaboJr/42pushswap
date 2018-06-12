/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_read_do.c                                       :+:      :+:    :+:   */
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

int	ps_read_do(char **line, t_list_num **list, t_list_num **blist)
{
	int i;

	i = 0;
	while (get_next_line(0, line) && (*line)[0])
	{
		if (!(ps_instruction(list, blist, *line)))
		{
			free(*line);
			return (0);
		}
		free(*line);
		i++;
	}
	return (1);
}
