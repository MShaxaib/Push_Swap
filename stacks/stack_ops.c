/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:39:42 by codespace         #+#    #+#             */
/*   Updated: 2024/02/13 21:41:11 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void stk_push(t_stack *stk, int value)
{

    t_node *new;
    
    new = malloc(sizeof(t_node));
    if(!new)
        return ;
    new -> content = value;
    new -> previous = NULL;
    if(!stk ->head)             // if there are no heads we make the new node the head and the tail
        stk->tail = new;
    else
    {
        new -> previous = stk->head;    // if there are nodes we give it the value and set the connection to the already present node
    } 
    stk->head = new;
    update_index(stk);
}


void stk_pop(t_stack *stk)
{
   t_node *temp;

    if (!stk || !stk->head)
        return;
    temp = stk->head;
    stk->head = stk->head->previous;
    if (!stk->head)
        stk->tail = NULL;
    update_index(stk);
    free(temp);
}

t_stack *create_stack_a(int *num_list, int list_size)
{
    t_stack *a;
    int i;
    
    a = init_stack();
    i = list_size - 1;
    while(i >= 0)
    {
        stk_push(a , num_list[i]);
        i--;
    }
    free(num_list);
    return(a);
}

t_stack *create_stack_b(t_stack *stk_a, int list_size)
{
    t_stack *b;

    b = init_stack();
    push_head(b, stk_a, 'b');
    if(list_size > 4)
        push_head(b,stk_a, 'b');
    return(b);
}
