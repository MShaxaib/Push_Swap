/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:29:17 by codespace         #+#    #+#             */
/*   Updated: 2024/01/26 14:34:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_stack.h"

/*
*   Done

*   sa  : swap the first 2 elements at the top of the stack a                        (Do nothing if only 1 or no elements)
*   sb  : swap the first 2 elements at the top of the stack b                        (Do nothing if only 1 or no elements)
*   ss  : sa and sb at the same time
*   ra  : shift up all the elements of stack a by 1                                  (The first element becomes the last one)
*   rb  : shift up all the elements of stack b by 1                                  (The first element becomes the last one)
*   pa  : take the first element at the top of b and put it at the top of a          (Do nothing if B is empty)
*   pb  : take the first element at the top of a and put it at the top of b          (Do nothing if A is empty)
*   rra : shift down all elements of stack a by 1                                    (The last element becomes the first one)
*   rrb : shift down all elements of stack b by 1                                    (The last element becomes the first one)
*   rrr : rra and rrb at the same time

^   Doing
^   1. Need to add conditions before doing any move
^   2. Need to print each move, i can either do that here by making new flags, or i can print them when i call each move

! To be done

*/

void sa(t_stack *stk_a)
{
    int temp;

    temp = stk_a->head->content;
    if(stk_a ->head != NULL && stk_a->head->previous != NULL)
    {
        stk_a->head->content = stk_a->head->previous->content;
        stk_a->head->previous = temp;
        printf("sa");
    }
}

void sb(t_stack *stk_b)
{
    int temp;

    temp = stk_b->head->content;
    if(stk_b ->head != NULL && stk_b->head->previous != NULL)
    {
        stk_b->head->content = stk_b->head->previous->content;
        stk_b->head->previous = temp;
        printf("sb");
    }
}

void ss(t_stack *stk_a, t_stack *stk_b)
{
    sa(stk_a);
    sb(stk_b);
    printf("ss");
}

void rotateStack(t_stack *stk)
{ 
    t_node *temp;
    
    temp = stk->head;
    if(!stk->head || !stk->head->previous)
        return(NULL);
    stk->head = stk->head->previous;
    temp->previous = NULL;
    
    stk->tail->previous = temp;
    temp->previous = NULL;
    stk->tail = stk->tail->previous;
}
void push_a(t_stack *stk_a, t_stack *stk_b)
{
    if(stk_b->head != NULL)
        return(NULL);
    stk_push(stk_a, stk_b->head->content);
    stk_pop(stk_b);
    printf("pa");
}

void push_b(t_stack *stk_a, t_stack *stk_b)
{
    if(stk_a != NULL)
        return(NULL);
    stk_push(stk_b, stk_a->head->content);
    stk_pop(stk_a);
    printf("pa");
}

void rev_rotate(t_stack *stk)
{
    t_node *current;
    int     value;
    
    if(!stk->head || !stk->head->previous)
        return(NULL);    
    current = stk->head;
    value = stk->tail->content;
    while(current->previous != stk->tail)
        current = current->previous;
    current->previous = NULL;
    stk_push(stk, value);
    free(stk->tail);
    stk->tail = current;
}
void rrr(t_stack *stk_a, t_stack *stk_b)
{
    rev_rotate(stk_a);
    rev_rotate(stk_b);
}