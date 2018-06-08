/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:46:14 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/29 13:32:49 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "checker.h"
#include "./libft/libft.h"

int	main(int argc, char **argv)
{
	t_list_num	*list;
	t_list_num	*blist;
	char		*line;
	int			size;

	line = NULL;
	list = NULL;
	blist = NULL;
	if (argc > 1 && !ps_get_input(argc, argv, &list))
		return (-1);
	size = ps_size(list);
	if (argc > 1 && !ps_read_do(&line, &list, &blist))
		return (-1);
	if (argc > 1)	
		ps_check_sort(list, size);
	ps_free(&list);
	return (0);
	// do a bonus where it prints the list?
	// do a bonus where it prints number of ins?
}
