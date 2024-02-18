/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_stk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:26:59 by codespace         #+#    #+#             */
/*   Updated: 2024/02/18 18:07:58 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	destroy_stacks(t_stack *a, t_stack *b, int list_size)
{
	ft_destroy(a);
	if (list_size > 3)
		ft_destroy(b);
}

void	ft_destroy(t_stack *stk)
{
	if (stk && !ft_is_empty(stk))
	{
		while (!ft_is_empty(stk))
			stk_pop(stk);
	}
	free(stk);
	stk = NULL;
}

int	ft_is_empty(t_stack *stk)
{
	return (stk->head == NULL);
}
