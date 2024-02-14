/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:10:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/14 22:40:29 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		// printf("this is stack a\n");
		// pstk(stk_a);
		// printf("this is stack B\n");
		// pstk(stk_b);
		mechanical_turk(stk_a, stk_b, 1);
	}
	sort_three(stk_a);
	while (stk_length(stk_b) != 0 )
	{
		// printf("this is stack a\n");
		// pstk(stk_a);
		// printf("this is stack B\n");
		// pstk(stk_b);
		mechanical_turk(stk_b, stk_a, 0);		
	}
	sort_stack(stk_a);
}
