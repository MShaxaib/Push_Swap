/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:29:17 by codespace         #+#    #+#             */
/*   Updated: 2024/01/23 16:33:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_stack.h"

/*
// Done

sa  : swpa the first 2 elements at the top of the stack a                        (Do nothing if only 1 or no elements)
sb  : swap the first 2 elements at the top of the stack b                        (Do nothing if only 1 or no elements)
ss  : sa and sb at the same time


// Doing

ra  : shift up all the elements of stack a by 1                                  (The first element becomes the last one)
rb  : shift up all the elements of stack b by 1                                  (The first element becomes the last one)


// To be done

pa  : take the first element at the top of b and put it at the top of a          (Do nothing if B is empty)
pb  : take the first element at the top of a and put it at the top of b          (Do nothing if A is empty)
rra : shift down all elements of stack a by 1                                    (The last element becomes the first one)
rrb : shift down all elements of stack b by 1                                    (The last element becomes the first one)
rrr : rra and rrb at the same time

*/

void sa(t_stack *stk_a)
{
    int temp;

    temp = stk_a->head->content;
    if(stk_a ->head != NULL && stk_a->head->next != NULL)
    {
        stk_a->head->content = stk_a->head->next->content;
        stk_a->head->next = temp;
        printf("sa");
    }
}

void sb(t_stack *stk_b)
{
    int temp;

    temp = stk_b->head->content;
    if(stk_b ->head != NULL && stk_b->head->next != NULL)
    {
        stk_b->head->content = stk_b->head->next->content;
        stk_b->head->next = temp;
        printf("sb");
    }
}

void ss(t_stack *stk_a, t_stack *stk_b)
{
    sa(stk_a);
    sb(stk_b);
    printf("ss");
}

void ra(t_stack *stk_a)
{
    
}