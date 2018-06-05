/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_convert_ins.c                                   :+:      :+:    :+:   */
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

int	ps_convert_ins(t_list_num **ins)
{
	t_list_num	*tmp;
	int			a;
	int			b;

	tmp = *ins;
	while (tmp && tmp->next)
	{
		a = tmp->num;
		b = tmp->next->num;
		if ((a == 1 && b == 2) || (a == 2 && b == 1))
			ps_overwrite(&tmp, 9, 12);
		else if ((a == 5 && b == 6) || (a == 6 && b == 5))
			ps_overwrite(&tmp, 10, 12);
		else if ((a == 7 && b == 8) || (a == 8 && b == 7))
			ps_overwrite(&tmp, 11, 12);
		else if ((a == 3 && b == 4) || (a == 4 && b == 3) ||
		(a == 5 && b == 7) || (a == 7 && b == 5) || (a == 6 && b == 8) ||
		(a == 8 && b == 6) || (a == 10 && b == 11) || (a == 11 && b == 10))
			ps_overwrite(&tmp, 12, 12);
		tmp = tmp->next;
	}
	ps_reverse_list(ins);
	return (1);
}
