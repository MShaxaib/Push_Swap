/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:10:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/13 19:56:48 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void put_min_on_top(t_stack *stk)
// {
// 	t_node *iter;
// 	t_node *current;
	
// 	iter = stk->head;

// 	while(iter != NULL)
// 	{
// 		if(iter->content < iter->previous->content)
// 			current = iter;
// 		iter = iter->previous;
// 	}
// 	if(current->index/stk_length(stk) <= 0.5)
// 		while(current->index != 0)
// 			rotate_stack(stk, 'b');
// 	else
// 		while(current->index != 0)
// 			rev_rotate(stk, 'b');
// }

void sort_three(t_stack *stk)
{
	t_node *max_value;

	max_value = find_max(stk);
	if(max_value == stk->head)
		rotate_stack(stk, 'a');
	else if (max_value == stk->head->previous)
		rev_rotate(stk, 'a');
	if (stk->head->content > stk->head->previous->content)
		sa(stk);
	update_index(stk);
}
void push_swap(t_stack *stk_a,t_stack *stk_b)
{
	while (stk_length(stk_a) > 3)
	{
		mechanical_turk(stk_a, stk_b, 1);
		printf("_________________________________________________________________\n");
	printf("this is stack a\n");
	pstk(stk_a);
	printf("this is stack b\n");
	pstk(stk_b);
	printf("_________________________________________________________________\n");
	}
	sort_three(stk_a);
	// put_min_on_top(stk_b);
	// printf("this is stack a\n");
	// pstk(stk_a);
	// printf("this is stack b\n");
	// pstk(stk_b);
	while (stk_length(stk_b) != 0 )
		mechanical_turk(stk_b, stk_a, 0);
}
