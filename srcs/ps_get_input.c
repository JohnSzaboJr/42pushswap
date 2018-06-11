/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:46:14 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/29 13:32:49 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../checker.h"
#include "../libft/libft.h"

int	ps_get_input(int argc, char **argv, t_list_num **list)
{
	int		i;
	int		l;
	char	**input;

	i = argc - 1;
	l = 0;
	while (i)
	{
		if (!(input = ft_strsplit(argv[i], ' ')))
			return (throw_error());
		while (input[l])
			l++;
		if (!ps_check_input(l, input) || !make_list(l, input, list))
			return (0);
		l = 0;
		while (input[l])
		{
			free(input[l]);
			l++;
		}
		free(input);
		l = 0;
		i--;
	}
	return (1);
}
