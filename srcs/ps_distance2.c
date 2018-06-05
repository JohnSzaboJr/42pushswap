/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_distance2.c                                     :+:      :+:    :+:   */
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

int	ps_distance2(t_list_num *list, t_list_num *blist)
{
	int p1;
	int p2;
	int sizeb;
	int sizea;
	int b;

	p1 = ps_smallest(blist);
	p2 = ps_position(list, ps_num(blist, p1) - 1);
	sizeb = ps_size(blist);
	sizea = ps_size(list);
	b = p1 < sizeb / 2 ? p1 : sizeb - p1;
	b = p2 < sizea / 2 ? p2 + b : sizea - p2 + b;
	return (b);
}
