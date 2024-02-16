/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:29:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/16 19:45:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	sa(t_stack *stk_a)
{
	int	cont;

	cont = stk_a->head->content;
	if (stk_a->head != NULL && stk_a->head->previous != NULL)
	{
		stk_a->head->content = stk_a->head->previous->content;
		stk_a->head->previous->content = cont;
		printf("sa\n");
	}
	update_index(stk_a);
}

void	sb(t_stack *stk_b)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	temp->content = stk_b->head->content;
	if (stk_b->head != NULL && stk_b->head->previous != NULL)
	{
		stk_b->head->content = stk_b->head->previous->content;
		stk_b->head->previous = temp;
		printf("sb\n");
	}
	update_index(stk_b);
}

void	ss(t_stack *stk_a, t_stack *stk_b)
{
	sa(stk_a);
	sb(stk_b);
	printf("ss\n");
}

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

/// @brief Pushed the head from dest to src
/// @param dest To push from
/// @param src to push to
/// @param flag 'a' if dest is A stack, 'b' if dest is B
void	push_head(t_stack *dest, t_stack *src, char flag)
{
	if (!src || !src->head || !dest)
		return ;
	if (flag == 'a')
		printf("pa\n");
	if (flag == 'b')
		printf("pb\n");
	stk_push(dest, src->head->content);
	stk_pop(src);
}

void	rrr(t_stack *stk_a, t_stack *stk_b)
{
	rev_rotate(stk_a, '2');
	rev_rotate(stk_b, 'n');
}
