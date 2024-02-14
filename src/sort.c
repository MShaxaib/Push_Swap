/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:49:57 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/14 19:32:04 by mshazaib         ###   ########.fr       */
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
		diff = iter->index + 1;
		while(i < diff)
		{
			rotate_stack(stk, 'a');
			i++;
		}
	}
	else
	{
		diff = ((stk_length(stk) - 1) - iter->index);
		while(i < diff)
		{
			rev_rotate(stk, 'a');
			i++;
		}
	}
}

void sort_stack(t_stack *stk)
{
	t_node *iter;

	iter = stk->head;
	while(iter->previous != NULL)
	{
		if(iter->content < iter->previous->content)
			iter = iter->previous;
		else
		{
			not_sorted(stk, iter);
			printf("the point of break is this %d------------------------>\n", iter->content);
			break;	
		}
	}
	
}