/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:52:43 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/19 13:10:12 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max(t_stack *stk)
{
	t_node	*max;
	t_node	*iter;

	if (stk->head)
		max = stk->head;
	if (stk->head->previous)
		iter = stk->head->previous;
	else
		return (stk->head);
	while (iter != NULL)
	{
		if (max->content < iter->content)
			max = iter;
		iter = iter->previous;
	}
	return (max);
}

t_node	*find_min(t_stack *stk)
{
	t_node	*min;
	t_node	*iter;

	min = stk->head;
	iter = stk->head->previous;
	while (iter != NULL)
	{
		if (min->content > iter->content)
			min = iter;
		iter = iter->previous;
	}
	return (min);
}
