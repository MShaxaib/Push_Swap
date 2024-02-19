/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mech_turk_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 05:08:17 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/19 13:08:50 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*smallest_weight(t_stack *stk)
{
	t_node	*iter;
	t_node	*min_node;

	min_node = stk->head;
	iter = min_node->previous;
	while (iter != NULL)
	{
		if (iter->weight < min_node->weight)
			min_node = iter;
		iter = iter->previous;
	}
	return (min_node);
}

void	set_rotations(t_node *min_node, t_stack *src_stk, t_stack *dest_stk)
{
	int	size_src;
	int	size_dest;

	size_src = stk_length(src_stk);
	size_dest = stk_length(dest_stk);
	if (min_node->index > (size_src / 2))
		src_stk->rev_rot_ctr = size_src - min_node->index;
	else
		src_stk->rot_ctr = min_node->index;
	if (min_node->target->index > (size_dest / 2))
		dest_stk->rev_rot_ctr = size_dest - min_node->target->index;
	else
		dest_stk->rot_ctr = min_node->target->index;
}

void	put_each_on_top(t_stack *src_stk, t_stack *dest_stk, int src_is_a)
{
	if (src_is_a == 1)
	{
		while (src_stk->rot_ctr--)
			rotate_stack(src_stk, 'a');
		while (src_stk->rev_rot_ctr--)
			rev_rotate(src_stk, 'a');
		while (dest_stk->rot_ctr--)
			rotate_stack(dest_stk, 'b');
		while (dest_stk->rev_rot_ctr--)
			rev_rotate(dest_stk, 'b');
	}
	else
	{
		while (src_stk->rot_ctr--)
			rotate_stack(src_stk, 'b');
		while (src_stk->rev_rot_ctr--)
			rev_rotate(src_stk, 'b');
		while (dest_stk->rot_ctr--)
			rotate_stack(dest_stk, 'a');
		while (dest_stk->rev_rot_ctr--)
			rev_rotate(dest_stk, 'a');
	}
}

void	put_to_top(t_stack *src_stk, t_stack *dest_stk, int src_is_a)
{
	while (src_stk->rot_ctr && dest_stk->rot_ctr)
	{
		rr(src_stk, dest_stk, 1);
		src_stk->rot_ctr--;
		dest_stk->rot_ctr--;
	}
	while (src_stk->rev_rot_ctr && dest_stk->rev_rot_ctr)
	{
		rrr(src_stk, dest_stk, 1);
		src_stk->rev_rot_ctr--;
		dest_stk->rev_rot_ctr--;
	}
	put_each_on_top(src_stk, dest_stk, src_is_a);
}
