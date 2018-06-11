/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_distance3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:10:29 by jszabo            #+#    #+#             */
/*   Updated: 2018/06/04 14:10:30 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../checker.h"
#include "../libft/libft.h"

int		ps_distance3(t_list_num *blist, int n)
{
	int p;
	int s;

	s = ps_size(blist);
	p = ps_position(blist, n);
	if (p == s)
		return (-1);
	return (p < s / 2) ? (p) : (s - p);
}
