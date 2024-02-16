/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mech_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:09:07 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/16 19:48:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_smaller_target(t_node *current_src, t_stack *b)
{
	t_node	*target;
	t_node	*current_b;

	current_b = b->head;
	target = NULL;
	current_b = b->head;
	while (current_b)
	{
		if ((current_b->content < current_src->content) && ((target == NULL)
				|| (current_b->content > target->content)))
			target = current_b;
		current_b = current_b->previous;
	}
	if (target == NULL)
		return (find_max(b));
	return (target);
}

t_node	*find_larger_target(t_node *current_src, t_stack *a)
{
	t_node	*target;
	t_node	*current_a;

	current_a = a->head;
	target = NULL;
	while (current_a)
	{
		if (current_a->content > current_src->content)
		{
			if (target == NULL || current_a->content < target->content)
			{
				target = current_a;
			}
		}
		current_a = current_a->previous;
	}
	if (target == NULL)
		return (find_min(a));
	return (target);
}

/// @brief Calculates the number of moves it takes to move each node
/// in src and its target in dest to the top of their stacks
/// @param src_idx src node's index
/// @param target_idx target nodes index
/// @param src_stk Stack A
/// @param target_stk Stack B
/// @return
int	calculate_cost(int src_idx, int target_idx, t_stack *src_stk,
		t_stack *target_stk)
{
	double	src_pos;
	double	target_pos;
	int		src_weight;
	int		target_weight;

	src_weight = 0;
	target_weight = 0;
	src_pos = (float)src_idx / (float)(stk_length(src_stk));
	target_pos = (float)target_idx / (float)(stk_length(target_stk));
	if (src_idx != 0)
	{
		if (src_pos <= 0.5)
			src_weight = src_idx;
		else
			src_weight = stk_length(src_stk) - src_idx;
	}
	if (target_idx != 0)
	{
		if (target_pos <= 0.5)
			target_weight = target_idx;
		else
			target_weight = stk_length(target_stk) - target_idx;
	}
	return (src_weight + target_weight);
}

void	mechanical_turk_ext(t_stack *src_stk, t_stack *dest_stk, int i)
{
	t_node	*min_node;

	min_node = NULL;
	if (i == 1)
	{
		min_node = smallest_weight(src_stk);
		put_to_top(min_node, src_stk, dest_stk, 1);
		push_head(dest_stk, src_stk, 'b');
	}
	else
	{
		min_node = smallest_weight(src_stk);
		put_to_top(min_node, src_stk, dest_stk, 0);
		push_head(dest_stk, src_stk, 'a');
	}
}

/// @brief implementation of the mechanical turk algorithm
/// @param a (to be changed to source) the source stack to be pushed from
/// @param b (to be changed to dest) the destination to push to
void	mechanical_turk(t_stack *src_stk, t_stack *dest_stk, int src_is_a)
{
	t_node	*current_src;

	current_src = src_stk->head;
	if (src_is_a == 1)
	{
		while (current_src != NULL)
		{
			current_src->target = find_smaller_target(current_src, dest_stk);
			current_src->weight = calculate_cost(current_src->index,
					current_src->target->index, src_stk, dest_stk);
			current_src = current_src->previous;
		}
		mechanical_turk_ext(src_stk, dest_stk, 1);
	}
	else if (src_is_a == 0)
	{
		current_src = src_stk->head;
		while (current_src != NULL)
		{
			current_src->target = find_larger_target(current_src, dest_stk);
			current_src->weight = calculate_cost(current_src->index,
					current_src->target->index, src_stk, dest_stk);
			current_src = current_src->previous;
		}
		mechanical_turk_ext(src_stk, dest_stk, 0);
	}
}
