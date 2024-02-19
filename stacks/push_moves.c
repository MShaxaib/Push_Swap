/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:29:17 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/19 13:11:26 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	sa(t_stack *stk_a, int c_flag)
{
	int	cont;

	if (!stk_a || !stk_a->head)
		return ;
	if (c_flag == 1)
		write(1, "sa\n", 3);
	else if (c_flag == 2)
		write(1, "ss\n", 3);
	cont = stk_a->head->content;
	if (stk_a->head != NULL && stk_a->head->previous != NULL)
	{
		stk_a->head->content = stk_a->head->previous->content;
		stk_a->head->previous->content = cont;
	}
	update_index(stk_a);
}

void	sb(t_stack *stk_b, int c_flag)
{
	t_node	*temp;

	if (!stk_b || !stk_b->head)
		return ;
	if (c_flag == 1)
		write(1, "sb\n", 3);
	temp = malloc(sizeof(t_node));
	temp->content = stk_b->head->content;
	if (stk_b->head != NULL && stk_b->head->previous != NULL)
	{
		stk_b->head->content = stk_b->head->previous->content;
		stk_b->head->previous = temp;
	}
	update_index(stk_b);
}

void	ss(t_stack *stk_a, t_stack *stk_b, int c_flag)
{
	if (c_flag == 1)
	{
		sa(stk_a, 2);
		sb(stk_b, 0);
	}
	else
	{
		sa(stk_a, 0);
		sb(stk_b, 0);
	}
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
		write(1, "pa\n", 3);
	else if (flag == 'b')
		write(1, "pb\n", 3);
	stk_push(dest, src->head->content);
	stk_pop(src);
}
