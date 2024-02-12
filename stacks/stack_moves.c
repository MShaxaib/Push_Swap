/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:29:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/12 11:51:08 by codespace        ###   ########.fr       */
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
    int cont;

    cont = stk_a->head->content;
    if(stk_a ->head != NULL && stk_a->head->previous != NULL)
    {
        stk_a->head->content = stk_a->head->previous->content;
        stk_a->head->previous->content = cont;
        printf("sa\n");
    }
    update_index(stk_a);
}

void sb(t_stack *stk_b)
{
    t_node *temp;
    
    temp = malloc(sizeof(t_node));
    temp->content = stk_b->head->content;
    if(stk_b ->head != NULL && stk_b->head->previous != NULL)
    {
        stk_b->head->content = stk_b->head->previous->content;
        stk_b->head->previous = temp;
        printf("sb\n");
    }
    update_index(stk_b);
}

void ss(t_stack *stk_a, t_stack *stk_b)
{
    sa(stk_a);
    sb(stk_b);
    printf("ss\n");
}

/// @brief Rotates the stack up shifting every node up by 1
/// @param stk 
/// @param c flag for printing | a = ra | b = rb | 2 = rr |
void rotate_stack(t_stack *stk, char c)
{ 
    t_node *temp;
    
    if (c == 'a')
        printf("ra\n");
    else if ('b')
        printf("rb\n");
    else if ('2')
        printf("rr\n");
    temp = stk->head;
    if(!stk->head || !stk->head->previous)
        return;
    stk->head = stk->head->previous;
    temp->previous = NULL;
    
    stk->tail->previous = temp;
    temp->previous = NULL;
    stk->tail = stk->tail->previous;
     update_index(stk);
}


/// @brief Pushed the head from dest to src
/// @param dest To push from
/// @param src to push to 
/// @param flag 'a' if dest is A stack, 'b' if dest is B
void push_head(t_stack *dest, t_stack *src, char flag)
{
    printf("pushing to head\n");
    if(!src || !src->head || !dest)
        return;
    if(flag == 'a')
        printf("pa\n");
    if(flag == 'b')
        printf("pb\n");
    stk_push(dest, src->head->content);
    stk_pop(src);
    // if(stk_length(src) > 0)
    // printf("reached here --------<><><><><>\n");
}


/// @brief Rotates the stack down shifting every node down by 1
/// @param stk 
/// @param c flag for printing | a = rra | b = rrb | 2 = rrr |
void rev_rotate(t_stack *stk, char c)
{
    t_node *current;
    int     value;
    
     if (c == 'a')
        printf("rra\n");
    else if ('b')
        printf("rrb\n");
    else if ('2')
        printf("rrr\n");
    if(!stk->head || !stk->head->previous)
        return;    
    current = stk->head;
    value = stk->tail->content;
    while(current->previous != stk->tail)
        current = current->previous;
    current->previous = NULL;
    stk_push(stk, value);
    update_index(stk);
    stk->tail = current;
   // printf("rra\n");
}
// void rrr(t_stack *stk_a, t_stack *stk_b)
// {
//     rev_rotate(stk_a, '2');
//     rev_rotate(stk_b, 'n');
// }

