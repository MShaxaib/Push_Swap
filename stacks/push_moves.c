/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:29:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/17 12:44:54 by mshazaib         ###   ########.fr       */
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
