/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 06:45:24 by codespace         #+#    #+#             */
/*   Updated: 2024/02/02 04:38:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
TO BE DONE 
   ! 1. Create both stacks and test out the moves and print moves as well as the values
   ^ 2. Start with the actual alorithm

DOING:

DONE:

*/


 void pstk(t_stack *stk)
 {
    // printf("print stack\n");
    t_node *iter;

    iter = stk->head;
    while(iter != NULL)
    {
        printf("%d\n", iter->content);
        iter = iter->previous;
    }
 }
 
int main(int argc, char **argv)
{
    int *num_list;
    int list_size;
    int i;

    i = 0;
    t_stack *a;
    t_stack *b;
    
    
    if (argc == 1)
        return 0;
    else if(argc == 2)  
        num_list = validator(++argv, 1, &list_size);
    else
        num_list = validator(getcharlist(++argv, argc, &list_size), argc - 1, &list_size);
    if(!num_list)
        printf("error in num_list\n");
    else
    {
        while(i < list_size)
            printf("%d\n", num_list[i++]);   
    }    
    printf("this is list_size:%d\n", list_size);
    // printf("\n");
    if(num_list != NULL)
    {
        if(is_sorted(num_list, list_size) == 1)
           return(free(num_list), 0);
        a = create_stack_a(num_list, list_size);
        b = NULL;
        push_swap(a, b, list_size);
        pstk(a);
        // pstk(a);
        // printf("----------\n");
        // sa(a);
        // printf("----------\n");
        // pstk(a);
        // b = create_stack_b(num_list, list_size);
        //     if(list_size is greater then 3 make stack b)
        // sort it
        //destroy and free
    }
}

