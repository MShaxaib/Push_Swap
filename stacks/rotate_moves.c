/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:44:34 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/18 12:53:05 by codespace        ###   ########.fr       */
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
	free(stk->tail);
	stk->tail = current;
	stk_push(stk, value);
}

void	rr(t_stack *stk_a, t_stack *stk_b, int c_flag)
{
	if(c_flag == 1)
	{
		rotate_stack(stk_a, '2');
		rotate_stack(stk_b, 'n');
	}
	else
	{
		rotate_stack(stk_a, '0');
		rotate_stack(stk_b, '0');
	}
		
}

void	rrr(t_stack *stk_a, t_stack *stk_b, int c_flag)
{
	if(c_flag == 1)
		{
			rev_rotate(stk_a, '2');
			rev_rotate(stk_b, 'n');	
		}
	else
		{
			rev_rotate(stk_a, '0');
			rev_rotate(stk_b, '0');	
		}
}
