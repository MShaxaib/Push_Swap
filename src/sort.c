/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:49:57 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/14 23:01:57 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void not_sorted(t_stack *stk, t_node *iter)
{
	int i;
	int diff;

	i = 0;
	if((float)(iter->index) / (float)stk_length(stk) >= 0.5 )
	{
		diff = (stk_length(stk) - iter->index);
		while(i < diff)
		{
			rev_rotate(stk, 'a');
			i++;
		}
	}
	else
	{
		diff = iter->index;
		while(i < diff)
		{
			rotate_stack(stk, 'a');
			i++;
		}
	}
}

void sort_stack(t_stack *stk)
{
	t_node *iter;

	// printf("%d | %d | %d\n", iter->content, iter->index, stk_length(stk));
	// iter = stk->head;
	// while(iter != NULL)
	// {
	// 	if(iter->content < iter->previous->content)
	// 		iter = iter->previous;
	// 	else
	// 	{
	// 		not_sorted(stk, iter);
	// 		break;	
	// 	}
	// }
	
	iter = find_min(stk);
	if (iter->index)
		not_sorted(stk, iter);
}