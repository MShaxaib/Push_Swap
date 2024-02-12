/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mech_turk_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 05:08:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/12 18:22:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief 
/// @param src 
/// @param rot if 1, rotate up, else rotate down 
void    put_a_to_top(t_stack *a, t_node *n,int rot)
{
	int i;
	if (rot == 1)
	{
		while (n->index != 0)
		{
			rotate_stack(a, 'a');
		}
	}
	else
	{
		i = n->index;
		while (i != 0)
		{
			rev_rotate(a, 'a');
			i--;
		}
	}
}
/// @brief 
/// @param src 
/// @param rot if 1, rotate up, else rotate down 
void	put_b_to_top(t_stack *b, t_node *n, int rot)
{
	int i;
	i = n->index;
	
	if(i > 0)
	{
		if(rot == 1)
		{
			while(i > 0)
			{
				rotate_stack(b, 'b');
				i--;
			}
		}
		else
			{
				while(i > 0)
				{
					rev_rotate(b, 'b');
					i--;
				}
				
			}
	}
	
	
	// printf("i is %d\n", i);
	// if (rot == 1)
	// {
	// 	i = n->index;
	// 	while (i != 0)
	// 	{
	// 		rotate_stack(b, 'b');
	// 		i--;
	// 	}
	// }
	// else
	// {
	// 	i = n->index;
	// 	while (i != 0)
	// 		{
	// 			rev_rotate(b, 'b');
	// 			i--;
	// 		}
	// }
}

float   calc_pos(t_stack *stk, t_node *n)
{
	// printf("the pos is : %f------------------------------------------------------------------------------------------->\n", calc_pos(stk, n->target));
	return ((float)n->index / (float) stk_length(stk));
}

void  put_to_top(t_node *cheapest_node, t_stack *src_stk, t_stack *dest_stk, int src_is_a)
{
	// int	target_idx;

	// target_idx = cheapest_node->target->index;
	if (src_is_a == 1)
	{
		if (calc_pos(src_stk, cheapest_node) <= 0.5)
			put_a_to_top(src_stk, cheapest_node, 1);
		else
			put_a_to_top(src_stk, cheapest_node, 0);
		if (calc_pos(dest_stk, cheapest_node->target) <= 0.5)
			put_b_to_top(dest_stk, cheapest_node->target, 1);
		else
			put_b_to_top(dest_stk, cheapest_node->target, 0);
	}
	else if (src_is_a == 0)
	{
		if (calc_pos(src_stk, cheapest_node) <= 0.5)
				put_b_to_top(src_stk, cheapest_node, 1);
		else
				put_b_to_top(src_stk, cheapest_node, 0);
		if (calc_pos(dest_stk, cheapest_node->target) <= 0.5)				
				put_a_to_top(dest_stk, cheapest_node->target, 1);
		else
				put_a_to_top(dest_stk, cheapest_node->target, 0);
	}
}
