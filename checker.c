/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:46:14 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/23 13:48:00 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "checker.h"
#include "./libft/libft.h"

static int	throw_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

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

static int	make_list(int argc, char **argv)
{
	t_list_num *list;
	t_list_num *tmp;

	tmp = NULL;
	list = NULL;
	argc--;
	while (argc > 0)
	{
		if (!(tmp = (t_list_num *)malloc(sizeof(*list))))
			return (throw_error());
		tmp->num = ft_atoi(argv[argc]);
		tmp->next = list;
		if (ps_duplicates(tmp, tmp->num))
            return (throw_error());
		list = tmp;
		argc--;
	}
	return (1);
}

int	is_not_int_size(char *str)
{
	return !(ft_atoll(str) >= -2147483648 && ft_atoll(str) <= 2147483647);
}

static int	check_input(int argc, char **argv)
{
	if (ft_avany(argv, argc, ft_hasnondigits) ||
		ft_avany(argv, argc, is_not_int_size))
		return (throw_error());
	return (1);
}

int	main(int argc, char **argv)
{
	char *line;

	line = NULL;
	if (argc > 1 && (!check_input(argc, argv) || !make_list(argc, argv)))
		return (-1);
//	while (get_next_line(0, &line))
//		printf("%s\n", line);
	return (0);
}
