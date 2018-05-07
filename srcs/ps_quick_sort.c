/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
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
//
#include <stdio.h>

void	ps_get_first(t_list_num *list, int start, int *first, int p, int last)
{
	ps_get_start(&list, start);
	while (list->num > p)
		list = list->next;
	if (list->num == p)
	{
		*first = list->num;
		list = list->next;
		while (list && list->next && list->num != last)
		{
			if (list->num < p)
				*first = list->num;
			list = list->next;
		}
		if (list->num == last && last < p)
			*first = list->num;
	}
	else
		*first = list->num;
}

void	ps_get_last(t_list_num *list, int *last, int p)
{
	int n;

	n = p;
	while (list && list->num != *last)
	{
		if (list->num > p)
			n = list->num;
		list = list->next;
	}
	*last = (*last > p) ? *last : n;
}

int	ps_position(t_list_num *list, int n)
{
	int i;

	i = 0;
	while (list && list->num != n)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	ps_qpre_sort(t_list_num **ins, t_list_num **blist)
{
	if (ps_size(*blist) == 2 && (*blist)->num < (*blist)->next->num)
	{
		ps_ins_switch(blist);
		ps_add_list(ins, 2);
	}
	else if (ps_size(*blist) == 3)
	{
		ps_print_list(*blist);
		if (ps_smallest(*blist) == 0 && (*blist)->next->num < (*blist)->next->next->num)
		{
			ps_ins_switch(blist);
			ps_add_list(ins, 2);
			ps_ins_rrotate(blist);
			ps_add_list(ins, 8);
			return ;
		}
		else if (ps_smallest(*blist) == 0)
		{
			ps_ins_rotate(blist);
			ps_add_list(ins, 6);
			return ;
		}
		else if (ps_smallest(*blist) == 1)
		{
			ps_ins_rrotate(blist);
			ps_add_list(ins, 8);
		}
		if (ps_smallest(*blist) == 2 && (*blist)->num < (*blist)->next->num)
		{
			ps_ins_switch(blist);
			ps_add_list(ins, 2);
			return ;
		}
	}
}

int	ps_is_rsort(t_list_num *list)
{
	while (list && list->next)
	{
		if (list->next->num > list->num)
			return (0);
		list = list->next;
	}
	return (1);
}

int	ps_largest(t_list_num *list)
{
    int largest;
    int pos;
    int l_pos;

    pos = 0;
    l_pos = 0;
    if (!list)
        return (-1);
    largest = list->num;
    while (list)
    {
        if (list->num >= largest)
        {
            largest = list->num;
            l_pos = pos;
        }
        list = list->next;
        pos++;
    }
    return (l_pos);
}

void	ps_qselect_sort(t_list_num **ins, t_list_num **blist, t_list_num **list)
{
	int pos;
	int size;

	while (*blist && !ps_is_rsort(*blist))
	{
		size = ps_size(*blist);
		pos = ps_largest(*blist);
		if (pos == 1)
		{
			ps_ins_switch(blist);
			ps_add_list(ins, 1);
			pos = 0;
		}
		while (pos <= size / 2 && pos > 0)
		{
			ps_ins_rotate(blist);
			ps_add_list(ins, 5);
			pos--;
		}
		while (pos > size / 2 && pos < size)
		{
			ps_ins_rrotate(blist);
			ps_add_list(ins, 7);
			pos++;
		}
		ps_ins_push(list, blist);
		ps_add_list(ins, 3);
	}
	if (*blist)
	{
		ps_ins_push(list, blist);
		ps_add_list(ins, 3);
	}
}

int ps_part(t_list_num **ins, t_list_num **list, int start, int end)
{
	int p;
	int	error;
	int	first;
	int	last;
	t_list_num  *blist;
	t_list_num	*clist;

	clist = NULL;
	blist = NULL;
	first = ps_num(*list, start);
	last = ps_num(*list, end);
	error = ps_find_pivot(*list, start, end, &p);
	printf("startlist:\n");
	ps_print_list(*list);
	printf("first:%d\n", first);
	printf("last:%d\n", last);
	printf("pivot:%d\n", p);
	printf("left:%d\n", ps_left(*list, p, start));
	if (!error)
		return (ps_position(*list, p));
	if (!ps_left(*list, p, start))
		{
			// ps_get_first(*list, start, &first, p, last);
			// printf("first: %d\n", first);
			while (ps_num(*list, ps_size(*list) - 1) != last)
			{
				ps_ins_rrotate(list);
				ps_add_list(ins, 7);
			}
			while ((*list)->num != p)
			{
				ps_ins_rrotate(list);
				ps_add_list(ins, 7);
				if ((*list)->num < p)
				{
					ps_ins_push(&blist, list);
					ps_add_list(ins, 4);
					error--;
				}
			}
			ps_qpre_sort(ins, &blist);
			ps_qselect_sort(ins, &blist, list);
			while (ps_size(blist))
				{
					ps_ins_push(list, &blist);
					ps_add_list(ins, 3);
				}
			first = (*list)->num;
			while (error)
			{
				ps_ins_rrotate(list);
				ps_add_list(ins, 7);
				if ((*list)->num > p)
				{
					ps_ins_push(&blist, list);	
					ps_add_list(ins, 4);
					error--;
				}
			}
			while ((*list)->num != p)
			{
				ps_ins_rotate(list);
				ps_add_list(ins, 5);
			}
			ps_ins_rotate(list);
			ps_add_list(ins, 5);

			ps_qpre_sort(ins, &blist);
			ps_qselect_sort(ins, &blist, list);
			while (ps_size(blist))
				{
					ps_ins_push(list, &blist);
					ps_add_list(ins, 3);
				}
			blist = *list;
			ps_get_start(list, start);
			while ((*list)->num != first)
			{
				ps_ins_rotate(&blist);
				ps_add_list(ins, 5);
				if ((*list)->next)
					*list = (*list)->next;
				else
					*list = blist;
			}
			*list = blist;
			blist = NULL;
		}
	else
	{
			ps_get_last(*list, &last, p);
			while (ps_num(*list, 0) != first)
			{
				ps_ins_rotate(list);
				ps_add_list(ins, 5);
			}
			while ((*list)->num != p)
			{
				if ((*list)->num > p)
				{
					ps_ins_push(&blist, list);
					ps_add_list(ins, 4);
					error--;
				}
				else
				{
					ps_ins_rotate(list);
					ps_add_list(ins, 5);
				}
			}
			ps_ins_rotate(list);
			ps_add_list(ins, 5);
			while (ps_size(blist))
				{
					ps_ins_push(list, &blist);
					ps_add_list(ins, 3);
				}
			while (error)
			{
				if ((*list)->num < p)
				{
					ps_ins_push(&blist, list);	
					ps_add_list(ins, 4);
					error--;
				}
				else
				{
					ps_ins_rotate(list);
					ps_add_list(ins, 5);
				}
			}
			//
			while ((*list)->num != p)
			{
				ps_ins_rrotate(list);
				ps_add_list(ins, 7);
			}
			ps_qpre_sort(ins, &blist);
			ps_qselect_sort(ins, &blist, list);
			while (ps_size(blist))
				{
					ps_ins_push(list, &blist);
					ps_add_list(ins, 3);
				}
			// most rotate-el van megoldva
			blist = *list;
			ps_get_start(list, end);
			while ((*list)->num != last)
			{
				ps_ins_rotate(&blist);
				ps_add_list(ins, 5);
				if ((*list)->next)
					*list = (*list)->next;
				else
					*list = blist;
			}
			*list = blist;
			blist = NULL;
		}
	ps_print_list(*list);
	return (ps_position(*list, p));

	// ideas to optimize:
	// optimize select sort for this situation
	// change rotate method
	// implement other tech at certain points
	// convert ins list to optimized
}

void	ps_quick_recursion(t_list_num **ins, t_list_num **list, int start, int end)
{
	int p;

	if (start >= end)
		return ;
	p = ps_part(ins, list, start, end);
	ps_quick_recursion(ins, list, start, p - 1);
	ps_quick_recursion(ins, list, p + 1, end);
}

int	ps_quick_sort(t_list_num **ins, t_list_num **list)
{
	ps_quick_recursion(ins, list, 0, ps_size(*list) - 1);
	return (1);
}