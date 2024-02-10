/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:39:42 by codespace         #+#    #+#             */
/*   Updated: 2024/02/10 21:24:02 by mshazaib         ###   ########.fr       */
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
    new -> previous = NULL;
    if(!stk ->head)             // if there are no heads we make the new node the head and the tail
        stk->tail = new;
    else // if there are nodes we give it the value and set the connection to the already present node
        new -> previous = stk->head;
    stk->head = new;
    //printf("the head is %d\n", stk->head->content);
    update_index(stk);
    // free(new);
    return(stk);
        
}


t_stack *stk_pop(t_stack *stk)
{
    t_node *temp;

    if (!stk || !stk->head)
		return (NULL);
    temp = stk->head;
    if(stk->head->previous != NULL)
        stk->head = stk->head->previous;
    temp->previous = NULL;
    update_index(stk);
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
        i--;
    }
    free(num_list);
    return(a);
}

t_stack *create_stack_b(t_stack *stk_a, int list_size)
{
    t_stack *b;

   // printf("making b\n");
    b = init_stack();
    push_head(b, stk_a, 'b');
    // push_b(stk_a, b);
    if(list_size > 4)
        push_head(b,stk_a, 'b');
        // push_b(stk_a, b);
   // printf("finished making b\n");
    return(b);
}