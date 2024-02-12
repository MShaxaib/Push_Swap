/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:39:42 by codespace         #+#    #+#             */
/*   Updated: 2024/02/12 12:15:33 by codespace        ###   ########.fr       */
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
    //printf("the head is %d\n", stk->head->content);
    // update_index(stk);
}


void stk_pop(t_stack *stk)
{
   t_node *temp;

    if (!stk || !stk->head)
        return;
    temp = stk->head;
    stk->head = stk->head->previous;

    // If head is NULL, set tail to NULL as well
    if (!stk->head)
        stk->tail = NULL;
    free(temp);
    update_index(stk);
    // t_node *temp;

    // if (!stk || !stk->head)
	// 	return ;
    // temp = stk->head;
    // if(stk->head->previous != NULL)
    //     stk->head = stk->head->previous;
    // temp->previous = NULL;
    // free(temp);
    // // return(void *)1;
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
 

// int main ()
// {
//     t_stack *stack;
    
//     stack = malloc(sizeof(t_stack));
//     stack->head = NULL;
//     stack->tail = NULL;

//     stk_push(stack, 1);
//     stk_push(stack, 2);
//     stk_push(stack, 3);
    
//     printf("----------------------------------------------------------------------------------\n");
//     while(stack->head != NULL)
//         {
//             printf("the head is %d\n", stack->head->content);
//             stk_pop(stack);
//         }
//     return(0);
// }