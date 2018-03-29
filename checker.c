/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:46:14 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/28 14:50:00 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "checker.h"
#include "./libft/libft.h"
//
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list_num	*list;
	t_list_num	*blist;
	char		*line;
	int			i;

	line = NULL;
	list = NULL;
       	blist = NULL;
	i = 0;
	if (argc > 1 && (!ps_check_input(argc, argv) ||
			!make_list(argc, argv, &list)))
		return (-1);
	while (get_next_line(0, &line) && line[0])
	{
		if (!(ps_instruction(&list, &blist, line)))
			return (-1);
		i++;
	}
	if (ps_no_input(i))
	  	return (-1);
	if (!i)
	{
		throw_error();
		return (-1);
	}
	while (list->next)
	{
		if (list->num > list->next->num)
		{
			ft_putstr("KO\n");
			return (0);
		}
		list = list->next;
	}
	ft_putstr("OK\n");
	// free the list
	return (0);
}
