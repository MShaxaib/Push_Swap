/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:29:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/18 12:56:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	sa(t_stack *stk_a, int c_flag)
{
	int	cont;

	if(c_flag == 1)
		printf("sa\n");
	else if (c_flag == 2)
		printf("ss\n");
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

	if(c_flag == 1)
		printf("sb\n");
	temp = malloc(sizeof(t_node));
	temp->content = stk_b->head->content;
	if (stk_b->head != NULL && stk_b->head->previous != NULL)
	{
		stk_b->head->content = stk_b->head->previous->content;
		stk_b->head->previous = temp;;
	}
	update_index(stk_b);
}

void	ss(t_stack *stk_a, t_stack *stk_b, int c_flag)
{
	if(c_flag == 1)
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
		printf("pa\n");
	else if (flag == 'b')
		printf("pb\n");
	stk_push(dest, src->head->content);
	stk_pop(src);
}
