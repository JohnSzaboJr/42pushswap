/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
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
	t_list_num	*list2;
	t_list_num	*blist;
	t_list_num	*ins;
	t_list_num	*ins2;

	list = NULL;
	list2 = NULL;
	blist = NULL;
    ins = NULL;
	ins2 = NULL;
	if (argc > 1 && (!ps_check_input(argc, argv) ||
			!make_list(argc, argv, &list) ||
			!make_list(argc, argv, &list2) ||
			!ps_solve(&ins, &ins2, &list, &list2, &blist)))
		return (-1);
	//ps_check_sort(list, argc - 1);
	//ps_free(&list);
	return (0);
}
