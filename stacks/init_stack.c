/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:26:07 by codespace         #+#    #+#             */
/*   Updated: 2024/01/27 16:14:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack *init_stack(void)
{
    t_stack *stk;

    stk = malloc(sizeof(t_stack));
    if(!stk)
        return(NULL);
        
    stk->head = NULL;
    stk->tail = NULL;
    return(stk);
}