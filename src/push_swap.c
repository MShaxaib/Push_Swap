/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:10:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/10 13:21:45 by mshazaib         ###   ########.fr       */
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
	// int pi = 0;

	// int stacklen = 0;


		// printf("\n*-*-*-*-*-**-*-**-*-**-*-**ITERATION %d -*-**-*-**-*-**-*-**-*-**-*-**-*-**-*-*\n",pi++);
		while (stk_length(stk_a) > 3)
		{
			mechanical_turk(stk_a, stk_b, 1);
			
		}
		sort_three(stk_a);
		// if(find_min(stk_b)->index <= stk_length(stk_b))
		// 	rev_rotate(stk_b, 'b');
		// else
		// 	rotate_stack(stk_b, 'b');
		
		
	
	// stacklen = stk_length(stk_b);
	// 	printf("stklen of b is : %d\n", stk_length(stk_b));
	// 	printf("stklen of a is : %d\n", stk_length(stk_a));

		while (stk_length(stk_b) < 3)
		{
			printf("length of stack B is %d\n:", stk_length(stk_a));
			printf("Hello\n");
			mechanical_turk(stk_b, stk_a, 0);
		}
}
