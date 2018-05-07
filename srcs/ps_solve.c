/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.c                                         :+:      :+:    :+:   */
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

int	ps_solve(int argc, char **argv, t_list_num **blist)
{
    // mindegyikhez rendelunk egyertelmuen egy szamot meret szerint
    // es aztan mar az egy kulonbseges szamokkal dolgozunk
    // igazabol felul is irhatjuk oket, es utana ezekkel dolgozunk
    // igy mindegyik szam egyben az idealis pozicioja is
    // mindegyik valtozasnal meg kell nezni hogy mi a kulonbsegek osszege
    // 6 ... 5 4 1 3 2 
    // let a = the distance from one on first number
    // a = total - diff + 1 = ordinal value of first number
    // let b = diffsum
    // foreach: b = b + abs(num - a);
    // check if step can reduce b
    // select the one that can reduce the most
    // if no reduction, check up to 3 steps ahead which leads to most reduction
    // and select that one?
    // at the end fix the absolute places?
    // or have another variable measuring absolute place difference, and 
    // minimize b + c? 
    // 6 ... 5 4 1 3 2 : b = 2 + 2 + 1 + 1 = 6
    // 6 ... 4 5 1 3 2 : b = 2 + 1 + 1 + 1 + 1 = 7
    // 6 ... 1 3 2 4 5 : b = 1 + 1 = 2
    // strategiak: 
    // - ha az elso ketto szomszedos, es rossz a sorrend: sa
    // - ha egy rotation az elejen vagy a vegen jo sorrende hoz?
    t_list_num *list;
    t_list_num *list2;
    t_list_num *ins;
    t_list_num *ins2;

    // ezeket a make_list-be?
    list = NULL;
    list2 = NULL;
    ins = NULL;
    ins2 = NULL;
    make_list(argc, argv, &list);
    make_list(argc, argv, &list2);
    ps_relative_sort(&ins, &list2);
    ps_select_sort(&ins, &list2, blist);
    ps_bubble_sort(&ins2, &list);
    if (ps_size(ins2) <  ps_size(ins))
    {
        ps_free(&ins);
        ins = ins2;
    }
    else
        ps_free(&ins2);
    ps_free(&list);
    make_list(argc, argv, &list);
    ps_convert_order(&list, list2);
    printf("original list:");
    ps_print_list(list);
    ps_quick_sort(&ins2, &list);

    printf("quick sorted:");
    ps_print_list(list);
    ps_print_list(*blist);
    ps_print_list(ins2);
    printf("ins:\n");
    // ha pa es pb van egymas mellett -> mindkettot torolni!
    ps_convert_ins(&ins);
   // ps_print_ins(ins);
    printf("%d\n", ps_size(ins));
    printf("%d\n", ps_size(ins2));
	return (1);
}