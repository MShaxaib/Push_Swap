/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 06:45:24 by codespace         #+#    #+#             */
/*   Updated: 2024/02/14 22:32:48 by mshazaib         ###   ########.fr       */
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
    t_node *iter;

    iter = stk->head;
    while(iter != NULL)
    {
        printf("|%d|\n", iter->content);
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
            push_swap(a, b);    
            // printf("\n----------------------\nStack after Push swap\n\n");
            // pstk(a);
        }
            // printf("Moves : %d\n", _moves_);
        // destroy_stacks(&a, &b, list_size);
    }
    return(0);
}

