/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:46:14 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/26 16:01:50 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "checker.h"
#include "./libft/libft.h"
//
#include <stdio.h>

static int	ps_duplicates(t_list_num *list, int num)
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

static int	make_list(int argc, char **argv, t_list_num **list)
{
	t_list_num *tmp;

	tmp = NULL;
	argc--;
	while (argc > 0)
	{
		if (!(tmp = (t_list_num *)malloc(sizeof(*tmp))))
			return (throw_error());
		tmp->num = ft_atoi(argv[argc]);
		tmp->next = *list;
		if (ps_duplicates(tmp, tmp->num))
            return (throw_error());
		*list = tmp;
		argc--;
	}
	return (1);
}

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
	if (argc > 1 && (!ps_check_input(argc, argv) || !make_list(argc, argv, &list)))
		return (-1);
	while (get_next_line(0, &line) && line[0])
	{
		if (!(ps_instruction(&list, &blist, line)))
			return (-1);
		i++;
	}
	if (!i)
	{
		throw_error();
		return (-1);
	}
	printf("%d\n", blist->num);
	printf("%d\n", list->num);
	return (0);
}

//every instruction to finish with new line?
