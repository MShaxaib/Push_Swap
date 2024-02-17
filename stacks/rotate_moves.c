/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:44:34 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/17 12:58:16 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

/// @brief Rotates the stack up shifting every node up by 1
/// @param stk
/// @param c flag for printing | a = ra | b = rb | 2 = rr |
void	rotate_stack(t_stack *stk, char c)
{
	t_node	*temp;

	if (!stk->head || !stk->head->previous)
		return ;
	if (c == 'a')
		printf("ra\n");
	else if (c == 'b')
		printf("rb\n");
	else if (c == '2')
		printf("rr\n");
	temp = stk->head;
	stk->head = stk->head->previous;
	temp->previous = NULL;
	stk->tail->previous = temp;
	stk->tail = stk->tail->previous;
	update_index(stk);
}

/// @brief Rotates the stack down shifting every node down by 1
/// @param stk
/// @param c flag for printing | a = rra | b = rrb | 2 = rrr |
void	rev_rotate(t_stack *stk, char c)
{
	t_node	*current;
	int		value;

	if (!stk->head || !stk->head->previous)
		return ;
	if (c == 'a')
		printf("rra\n");
	else if (c == 'b')
		printf("rrb\n");
	else if (c == '2')
		printf("rrr\n");
	current = stk->head;
	value = stk->tail->content;
	while (current->previous != stk->tail)
		current = current->previous;
	current->previous = NULL;
	stk->tail = current;
	stk_push(stk, value);
}

void	rr(t_stack *stk_a, t_stack *stk_b)
{
	rotate_stack(stk_a, '2');
	rotate_stack(stk_b, 'n');
}

void	rrr(t_stack *stk_a, t_stack *stk_b)
{
	rev_rotate(stk_a, '2');
	rev_rotate(stk_b, 'n');
}
