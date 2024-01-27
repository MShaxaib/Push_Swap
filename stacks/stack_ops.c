/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:39:42 by codespace         #+#    #+#             */
/*   Updated: 2024/01/27 16:15:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack *stk_push(t_stack *stk, int value)
{

    t_node *new;
    
    new = malloc(sizeof(t_node));
    if(!new)
        return(NULL);
    new -> content = value;
    if(!stk ->head)             // if there are no heads we make the new node the head and the tail
    {
        stk->tail = new;
        new->previous = NULL;
    }   
    else // if there are nodes we give it the value and set the connection to the already present node
        new -> previous = stk->head;
    stk ->head = new;    
    return(stk);
        
}


t_stack *stk_pop(t_stack *stk)
{
    t_node *temp;

    temp = malloc(sizeof(t_node));
    stk->head = temp;
    if(stk->head->previous != NULL)
        stk->head = stk->head->previous;
    stk->head->previous = NULL;
    free(temp);
    return(stk);
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
        i --;
    }
    free(num_list);
    return(a);
}
// t_stack *create_stack_b(int *num_list, int list_size)
// {
//     t_stack *b;
//     int i;
    
//     b = init_stack();
//     i = list_size - 1;

//     while(i > 0)
//         stk_push(b , num_list[i--]);
//     free(num_list);
//     return(b);
// }
// t_stack *create_stack_b(t_stack *a, int list_size)
// {
//     t_stack *b;

//     b = init_stack();
    
// }