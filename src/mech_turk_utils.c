/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mech_turk_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 05:08:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/10 13:24:53 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief 
/// @param src 
/// @param rot if 1, rotate up, else rotate down 
void    put_a_to_top(t_stack *a, t_node *n,int rot)
{
		// printf("\n\n\n\nthe index of n is %d: \n", n->index);
	// if (n->index == 0)
	// 	printf("dont do anything");
	if (rot == 1)
	{
		while (n->index != 0)
			{
				// printf("<><><><><><><><><><><>should rotate<><><><><><><><><><><>\n");
				rotate_stack(a, 'a');
			}
	}
	else
	{
		while (n->index != 0)
		{
			rev_rotate(a, 'a');
			// printf("<><><><><><><><><><><>should rev rotate<><><><><><><><><><><>\n");

		}
	}
}
/// @brief 
/// @param src 
/// @param rot if 1, rotate up, else rotate down 
void	put_b_to_top(t_stack *b, t_node *n, int rot)
{
	if (rot == 1)
		while (n->index != 0)
			rotate_stack(b, 'b');
	else
		while (n->index != 0)
			rev_rotate(b, 'b');
}

float   calc_pos(t_stack *stk, t_node *n)
{
	return ((float)n->index / (float) stk_length(stk));
}

void  put_to_top(t_node *cheapest_node, t_stack *src_stk, t_stack *dest_stk, int src_is_a)
{
	// printf("In the process of putting to top\n");
	// printf("the cheapest node is %d and its index is %d\n", cheapest_node->content, cheapest_node->index);
	int	target_idx;

	target_idx = cheapest_node->target->index;
	// printf("the target's index is = %d\n", target_idx);
	// printf("the cheapest node is %d\n", cheapest_node->index);
	if (src_is_a == 1)
	{
		// printf("<><><><><><><><><><><>is in the loop<><><><><><><><><><><>\n");
		if (calc_pos(src_stk, cheapest_node) <= 0.5)
		{
			// printf("should put the cheapest node in A on top with rotating\n");
			put_a_to_top(src_stk, cheapest_node, 1);
		}
		else
		{
			// printf("should put the cheapest node in A on top with rev rot\n");
			put_a_to_top(src_stk, cheapest_node, 0);
		}
		if (calc_pos(src_stk, cheapest_node->target) <= 0.5)
		{
			// printf("should put the cheapest node in B on top with rotating\n");
			// printf("less than median\n");
			put_b_to_top(dest_stk, cheapest_node->target, 1);
		}
		else
		{
			// printf("should put the cheapest node in B on top with rotating\n");
			put_b_to_top(dest_stk, cheapest_node->target, 0);
		}
	}
	else
	{
		if (calc_pos(src_stk, cheapest_node) <= 0.5)
			put_b_to_top(src_stk, cheapest_node, 1);
		else
			put_b_to_top(src_stk, cheapest_node, 0);
		if (calc_pos(src_stk, cheapest_node->target) <= 0.5)
			  put_a_to_top(dest_stk, cheapest_node->target, 1);
		else
			put_a_to_top(dest_stk, cheapest_node->target, 0);
	}
}
