/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:39:42 by codespace         #+#    #+#             */
/*   Updated: 2024/02/12 18:15:56 by codespace        ###   ########.fr       */
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



//!-----------------------------------------------------------------------------------------------------------------------------------------------
// void rotate_stack(t_stack *stk, char c)
// { 
//     t_node *temp;
    
//     if(!stk->head || !stk->head->previous)
//         return;
//     if (c == 'a')
//         printf("ra\n");
//     else if (c == 'b')
//         printf("rb\n");
//     else if (c == '2')
//         printf("rr\n");
//     temp = stk->head;
//     stk->head = stk->head->previous;
//     temp->previous = NULL;
//     stk->tail->previous = temp;
//     stk->tail = stk->tail->previous;
//     update_index(stk);
// }
// /// @brief Rotates the stack down shifting every node down by 1
// /// @param stk 
// /// @param c flag for printing | a = rra | b = rrb | 2 = rrr |
// void rev_rotate(t_stack *stk, char c)
// {
//     t_node *current;
//     int     value;
    
//     if(!stk->head || !stk->head->previous)
//         return;   
//     if (c == 'a')
//         printf("rra\n");
//     else if (c =='b')
//         printf("rrb\n");
//     else if (c == '2')
//         printf("rrr\n");
//     current = stk->head;
//     value = stk->tail->content;
    
//     while(current->previous != stk->tail)
//              current = current->previous;
//     current->previous = NULL;
//     stk->tail = current;
//     stk_push(stk, value);
//     update_index(stk);
//    // printf("rra\n");
// }

//  void pstk(t_stack *stk)
//  {
//     // printf("print stack\n");
//     t_node *iter;

//     iter = stk->head;
//     while(iter != NULL)
//     {
//         printf("|%d|\n", iter->content);
//         iter = iter->previous;
//     }
//  }

// int main ()
// {
//     t_stack *stack;
    
//     stack = malloc(sizeof(t_stack));
//     stack->head = NULL;
//     stack->tail = NULL;

//     stk_push(stack, 25);
//     stk_push(stack, 99);
//     stk_push(stack, 0);
    
//     // printf("----------------------------------------------------------------------------------\n");
//    pstk(stack);
//     printf("----------------------------------------------------------------------------------\n");
//    rev_rotate(stack,'a');
//        printf("----------------------------------------------------------------------------------\n");
//    pstk(stack);
//     // while(stack->head != NULL)
//     //     {
//     //         printf("the head is %d\n", stack->head->content);
//     //         stk_pop(stack);
//     //     }
//     return(0);
// }