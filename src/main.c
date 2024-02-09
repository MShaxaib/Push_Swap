/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 06:45:24 by codespace         #+#    #+#             */
/*   Updated: 2024/02/09 23:31:56 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
TO BE DONE:
    ^   rotate each element and its target node to the top of each of their respective stacks
    ^   

    

DOING:
    
DONE:
   * 1. Create both stacks and test out the moves and print moves as well as the values
   * 2. Start with the actual alorithm
   * 3. Calculute the target node 
   * 4. Calculate the weight 
        ^ needs to be optomized 

*/


 void pstk(t_stack *stk)
 {
    // printf("print stack\n");
    t_node *iter;

    iter = stk->head;
    while(iter != NULL)
    {
        printf("|%d|\n\n", iter->content);
        iter = iter->previous;
    }
 }
 
int main(int argc, char **argv)
{
    int *num_list;
    int list_size;
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
    printf("<----------MOVES--------->\n");
    // printf("\n");
    if(num_list != NULL)
    {
        if(is_sorted(num_list, list_size) == 1)
           return(free(num_list), 0);
        a = create_stack_a(num_list, list_size); 
        if(list_size == 2)
            sa(a);
        if(list_size == 3)
             sort_three(a);
        if(list_size > 3)
        {
            b = create_stack_b(a, list_size);
            printf("\nStack A before Push Swap\n");
            pstk(a);
            printf("\nStack B before Push Swap\n");
            pstk(b);
            push_swap(a, b);
            printf("\nStack A after Push Swap\n");
            pstk(a);
            printf("\nStack B after Push Swap\n");
            pstk(b);
        // pstk(a);
        // printf("----------\n");
        // sa(a);
        // printf("----------\n");
        // pstk(a);
        // b = create_stack_b(num_list, list_size);
        //     if(list_size is greater then 3 make stack b)
        // sort it
        //destroy and free
        // pstk(b);
        }
    }
}
