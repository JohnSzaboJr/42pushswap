/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:46:14 by jszabo            #+#    #+#             */
/*   Updated: 2018/06/12 13:36:56 by jszabo           ###   ########.fr       */
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
	int			e;

	line = NULL;
	list = NULL;
	blist = NULL;
	e = 0;
	if (argc > 1 && !ps_get_input(argc, argv, &list))
		return (-1);
	if (argc > 1 && list && !ps_read_do(&line, &list, &blist))
		e = 1;
	if (!e && argc > 1 && (list || blist))
		ps_check_sort(list, blist);
	ps_free(&blist);
	ps_free(&list);
	return (e) ? (1) : (0);
}
