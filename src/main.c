/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 06:45:24 by codespace         #+#    #+#             */
/*   Updated: 2024/01/26 15:02:12 by codespace        ###   ########.fr       */
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
int main(int argc, char **argv)
{
    int *num_list;
    int list_size;
    int i;

    i = 0;
    t_stack *a;
    // t_stack *b;
    
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
            printf("%d", num_list[i++]);   
    }
    printf("\n");
    free(num_list);
    if(num_list)
    {
        if(is_sorted(num_list, list_size) == 1)
           return(free(num_list), 0);
        a = create_stack_a(num_list, list_size);
        print_the_stack(a);
        // b = create_stack_b(num_list, list_size);
        //     if(list_size is greater then 3 make stack b)
        // sort it
        //destroy and free
    }
}

 void print_the_stack(t_stack *stk)
 {
    t_node *iter;
    
    while(iter->previous != stk->tail)
    {
        printf("%d", iter->content);
        iter = iter->previous;
    }
 }
