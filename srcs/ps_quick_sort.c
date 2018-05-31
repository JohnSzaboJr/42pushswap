// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ps_quick_sort.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2018/03/23 14:31:23 by jszabo            #+#    #+#             */
// /*   Updated: 2018/03/23 14:35:38 by jszabo           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <unistd.h>
// #include "../checker.h"
// #include "../libft/libft.h"
// //
// #include <stdio.h>

// int	ps_is_rsort(t_list_num *list)
// {
// 	while (list && list->next)
// 	{
// 		if (list->next->num > list->num)
// 			return (0);
// 		list = list->next;
// 	}
// 	return (1);
// }

// int	ps_largest(t_list_num *list)
// {
//     int largest;
//     int pos;
//     int l_pos;

//     pos = 0;
//     l_pos = 0;
//     if (!list)
//         return (-1);
//     largest = list->num;
//     while (list)
//     {
//         if (list->num >= largest)
//         {
//             largest = list->num;
//             l_pos = pos;
//         }
//         list = list->next;
//         pos++;
//     }
//     return (l_pos);
// }

// void	ps_qselect_sort(t_list_num **ins, t_list_num **blist, t_list_num **list)
// {
// 	int pos;
// 	int size;

// 	while (*blist && !ps_is_rsort(*blist))
// 	{
// 		size = ps_size(*blist);
// 		pos = ps_largest(*blist);
// 		if (pos == 1)
// 		{
// 			ps_ins_switch(blist);
// 			ps_add_list(ins, 1);
// 			pos = 0;
// 		}
// 		while (pos <= size / 2 && pos > 0)
// 		{
// 			ps_ins_rotate(blist);
// 			ps_add_list(ins, 5);
// 			pos--;
// 		}
// 		while (pos > size / 2 && pos < size)
// 		{
// 			ps_ins_rrotate(blist);
// 			ps_add_list(ins, 7);
// 			pos++;
// 		}
// 		ps_ins_push(list, blist);
// 		ps_add_list(ins, 3);
// 	}
// 	if (*blist)
// 	{
// 		ps_ins_push(list, blist);
// 		ps_add_list(ins, 3);
// 	}
// }

// // void	ps_get_prev(t_list_num **list, t_list_num *node)
// // {
// // 	int	num;

// // 	num  = (*list)->num;
// // 	while (node && node->next && node->next->num != num)
// // 	{
// // 		node = node->next;
// // 	}
// // 	*list = node;
// // }

// // void	ps_rrotate_n(t_list_num **list, int	n, t_list_num **ins)
// // {
// // 	while (n)
// // 	{
// // 		ps_ins_rrotate(list);
// // 		ps_add_list(ins, 7);
// // 		n--;
// // 	}
// // }

// // void	ps_rotate_n(t_list_num **list, int	n, t_list_num **ins)
// // {
// // 	while (n)
// // 	{
// // 		ps_ins_rotate(list);
// // 		ps_add_list(ins, 5);
// // 		n--;
// // 	}
// // }

// // void	ps_rotate_into_place(t_list_num **list, int end, int last, t_list_num **ins)
// // {
// // 	int			pos;

// // 	pos = ps_position(*list, last);
// // 	if (pos < end && (end - pos) < (ps_size(*list) / 2))
// // 		ps_rrotate_n(list, end - pos, ins);
// // 	else if (pos < end && (end - pos) >= (ps_size(*list) / 2))
// // 		ps_rotate_n(list, ps_size(*list) - (end - pos), ins);
// // 	else if (pos > end && (pos - end) < (ps_size(*list) / 2))
// // 		ps_rotate_n(list, pos - end, ins);
// // 	else if (pos > end && (pos - end) >= (ps_size(*list) / 2))
// // 		ps_rrotate_n(list, ps_size(*list) - (pos - end), ins);
// // }

// int ps_part(t_list_num **ins, t_list_num **list, int start, int end)
// {
// 	int p;
// 	int	error;
// 	int	first;
// 	int	last;
// 	t_list_num  *blist;

// 	blist = NULL;
// 	first = ps_num(*list, start);
// 	last = ps_num(*list, end);
// 	error = ps_find_pivot(*list, start, end, &p);
// 	printf("startlist:\n");
// 	ps_print_list(*list);
// 	printf("first:%d\n", first);
// 	printf("last:%d\n", last);
// 	printf("pivot:%d\n", p);
// 	printf("left:%d\n", ps_left(*list, p, start));
// 	if (!error)
// 		return (ps_position(*list, p));
// 	if (!ps_left(*list, p, start))
// 		{
// 			ps_get_first(*list, start, &first, p);
// 			printf("first: %d\n", first);
// 			while (ps_num(*list, ps_size(*list) - 1) != last)
// 			{
// 				ps_ins_rrotate(list);
// 				ps_add_list(ins, 7);
// 			}
// 			while ((*list)->num != p)
// 			{
// 				ps_ins_rrotate(list);
// 				ps_add_list(ins, 7);
// 				if ((*list)->num < p)
// 				{
// 					ps_ins_push(&blist, list);
// 					ps_add_list(ins, 4);
// 					error--;
// 				}
// 			}
// 			// ps_qpre_sort(ins, &blist);
// 			ps_qselect_sort(ins, &blist, list);
// 				while (ps_size(blist))
// 				{
// 					ps_ins_push(list, &blist);
// 					ps_add_list(ins, 3);
// 				}


// 			while (error)
// 			{
// 				ps_ins_rrotate(list);
// 				ps_add_list(ins, 7);
// 				if ((*list)->num > p)
// 				{
// 					ps_ins_push(&blist, list);	
// 					ps_add_list(ins, 4);
// 					error--;
// 				}
// 			}
// 			//
// 			while ((*list)->num != p)
// 			{
// 				ps_ins_rotate(list);
// 				ps_add_list(ins, 5);
// 			}
// 			// ps_ins_rotate(list);
// 			// ps_add_list(ins, 5); 
// 			// ps_qpre_sort(ins, &blist);
// 			// if (ps_size(blist) < 8)
// 				ps_qselect_sort(ins, &blist, list);
// 			while (ps_size(blist))
// 				{
// 					ps_ins_push(list, &blist);
// 					ps_add_list(ins, 3);
// 				}
// 			ps_rotate_into_place(list, start, first, ins);
// 		}
// 	else
// 	{
// 			ps_get_last(*list, &last, p);
// 			printf("LAST: %d\n", last);
// 			while (ps_num(*list, 0) != first)
// 			{
// 				ps_ins_rotate(list);
// 				ps_add_list(ins, 5);
// 			}
// 			while ((*list)->num != p)
// 			{
// 				if ((*list)->num > p)
// 				{
// 					ps_ins_push(&blist, list);
// 					ps_add_list(ins, 4);
// 					error--;
// 				}
// 				else
// 				{
// 					ps_ins_rotate(list);
// 					ps_add_list(ins, 5);
// 				}
// 			}
// 			ps_ins_rotate(list);
// 			ps_add_list(ins, 5);
// 			while (ps_size(blist))
// 				{
// 					ps_ins_push(list, &blist);
// 					ps_add_list(ins, 3);
// 				}
// 			while (error)
// 			{
// 				if ((*list)->num < p)
// 				{
// 					ps_ins_push(&blist, list);	
// 					ps_add_list(ins, 4);
// 					error--;
// 				}
// 				else
// 				{
// 					ps_ins_rotate(list);
// 					ps_add_list(ins, 5);
// 				}
// 			}
// 			while ((*list)->num != p)
// 			{
// 				ps_ins_rrotate(list);
// 				ps_add_list(ins, 7);
// 			}
// 			// ps_qpre_sort(ins, &blist);
// 				ps_qselect_sort(ins, &blist, list);
// 			while (ps_size(blist))
// 				{
// 					ps_ins_push(list, &blist);
// 					ps_add_list(ins, 3);
// 				}
// 			ps_rotate_into_place(list, end, last, ins);
// 		}
// 	ps_print_list(*list);
// 	return (ps_position(*list, p));

// 	// ideas to optimize:
// 	// try to optimize rotating here and there...
// 	// implement other tech at certain points
// 	// convert ins list to optimized
// }

// void	ps_find_next(t_list_num *list, int *start, int *end)
// {
// 	int length;
// 	int i;
// 	int j;
// 	int st;
// 	int et;

// 	length = 1;
// 	*start = 0;
// 	*end = 0;
// 	j = 0;

// 	while (list && list->next)
// 	{
// 		i = 1;
// 		st = j;
// 		while (list->next && ((list->num) + 1 != list->next->num))
// 		{
// 			list = list->next;
// 			i++;
// 			j++;
// 		}
// 		et = j;
// 		if (i > length)
// 		{
// 			length = i;
// 			*start = st;
// 			*end = et;
// 		}
// 		while (list->next && ((list->num) + 1 == list->next->num))
// 		{
// 			list = list->next;
// 			j++;
// 		}
// 		if (list && list->next)
// 		{
// 			list = list->next;
// 			j++;
// 		}
// 	}
// 	printf("START: %d\n", *start);
// 	printf("END: %d\n", *end);
// }


// void	ps_quick_recursion(t_list_num **ins, t_list_num **list, int start, int end)
// {
// 	int p;

// 	if (start >= end)
// 		return ;
// 	p = ps_part(ins, list, start, end);

// 	p = ps_part(ins, list, p + 1, end);
// 	p = ps_part(ins, list, start, p - 1);
	



// 	// ps_quick_recursion(ins, list, p + 1, end);
	
// 	// ps_quick_recursion(ins, list, start, p - 1);
// 	// ps_quick_recursion(ins, list, p + 1, end);
// }

// void	ps_rrotate_push_n(t_list_num **list, t_list_num **blist, int	n, t_list_num **ins)
// {
// 	while (n)
// 	{
// 		ps_ins_rrotate(list);
// 		ps_add_list(ins, 7);
// 		ps_ins_push(blist, list);
// 		ps_add_list(ins, 4);
// 		n--;
// 	}
// }

// void	ps_push_n(t_list_num **list, t_list_num **blist, int	n, t_list_num **ins)
// {
// 	while (n)
// 	{
// 		ps_ins_push(blist, list);
// 		ps_add_list(ins, 4);
// 		n--;
// 	}
// }

// int		ps_done(t_list_num *list, t_list_num *blist)
// {
// 	int i;

// 	i = 0;
// 	if (blist)
// 		return (0);
// 	while (list && list->next)
// 	{
// 		if (list->num + 1 != list->next->num)
// 			i++;
// 		list = list->next;
// 	}
// 	return (i <= 1) ? (1) : (0);
// }

// void	ps_final_sort(t_list_num **ins, t_list_num **list, t_list_num **blist)
// {
// 	int			pos;
// 	int			next;

// 	pos = ps_position(*list, 1);
// 	if (pos < 0 && (0 - pos) < (ps_size(*list) / 2))
// 		ps_rrotate_push_n(list, blist, 0 - pos, ins);
// 	else if (pos < 0 && (0 - pos) >= (ps_size(*list) / 2))
// 		ps_push_n(list, blist, ps_size(*list) - (0 - pos), ins);
// 	else if (pos > 0 && (pos - 0) < (ps_size(*list) / 2))
// 		ps_push_n(list, blist, pos - 0, ins);
// 	else if (pos > 0 && (pos - 0) >= (ps_size(*list) / 2))
// 		ps_rrotate_push_n(list, blist, ps_size(*list) - (pos - 0), ins);
// 	// if sorted -> return

// 	while (!ps_done(*list, *blist))
// 	{
// 	while (*list && (*list)->next && (*list)->num + 1 == (*list)->next->num)
// 	{
// 		ps_ins_rotate(list);
// 		ps_add_list(ins, 5);
// 	}
// 	next = (*list)->num + 1;
// 	ps_ins_rotate(list);
// 	ps_add_list(ins, 5);
// 	if (ps_position(*blist, next) != ps_size(*blist))
// 	{
// 		ps_rotate_into_place(blist, 0, next, ins);
// 		ps_ins_push(list, blist);
// 		ps_add_list(ins, 3);
// 	}
// 	else
// 	{
// 		while ((*list)->num != next)
// 			{
// 				ps_ins_push(blist, list);
// 				ps_add_list(ins, 4);
// 			}
// 	}
// 	}
// 	ps_rotate_into_place(list, 0, 1, ins);
// }


// int	ps_quick_sort(t_list_num **ins, t_list_num **list)
// {
// 	t_list_num *blist;
// 	blist = NULL;
// 	ps_quick_recursion(ins, list, 0, ps_size(*list) - 1);
// 	ps_final_sort(ins, list, &blist);
// 	return (1);
// }