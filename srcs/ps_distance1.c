/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_distance1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:08:49 by jszabo            #+#    #+#             */
/*   Updated: 2018/06/04 14:08:50 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../checker.h"
#include "../libft/libft.h"

int      ps_distance1(t_list_num *list, t_list_num *blist)
{
	int p1;
	int p2;
	int sizeb;
	int sizea;
	int a;

	p1 = ps_position(blist, ps_largest_num(blist));
	p2 = ps_position(list, ps_largest_num(blist) + 1);
	sizeb = ps_size(blist);
	sizea = ps_size(list);
	a = p1 < sizeb / 2 ? p1 : sizeb - p1;
	a = p2 < sizea / 2 ? p2 + a : sizea - p2 + a;
	return (a);
}