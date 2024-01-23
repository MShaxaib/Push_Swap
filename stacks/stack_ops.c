/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:39:42 by codespace         #+#    #+#             */
/*   Updated: 2024/01/22 07:36:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack *stk_push(t_stack *stk, int value)
{
    t_node *new;
    t_node *temp;

    new = malloc(sizeof(t_node));
    temp->content = value;
    if(!new)
        return(NULL);
    if(new == NULL)
    {
        new = temp;
        new->next = NULL;
    }
    else
    {
       temp->next = new;
       new = temp;
    } 
}

t_stack *stk_pop(t_stack *stk)
{
    t_node *temp;

    stk->head = temp;

    if(stk->head)
        stk->head->next = NULL;
    free(temp);
    return(stk);
}

t_stack *create_stack_a(int *num_list, int list_size)
{
    t_stack *a;
    int i;
    
    a = init_stack();
    i = list_size - 1;

    while(i > 0)
        stk_push(a , num_list[i--]);
    free(num_list);
    return(a);
}

// t_stack *create_stack_b(t_stack *a, int list_size)
// {
//     t_stack *b;

//     b = init_stack();
    
// }