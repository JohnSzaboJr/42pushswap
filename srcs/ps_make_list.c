/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_make_list.c                                     :+:      :+:    :+:   */
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

int	make_list(int argc, char **argv, t_list_num **list)
{
	t_list_num *tmp;

	tmp = NULL;
	argc--;
	while (argc >= 0)
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
