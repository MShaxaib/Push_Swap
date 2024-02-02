/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:10:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/01 08:16:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
    ^   Algrothim's logic
        
    *   1.  Push the top 2 nodes from  A -> B
    *   2.  Calculate the target node i.e (closest smallest number)
            !   if cant find then the max value is the target node
    *   3.  Cost analysis
    *   4.  Move the cheapest and repeat until 3 nodes left in A
    *   5.  Sort 3 in A
    *   6.  Now we have to move all from B -> A 
    *   7.  Calculate weights in reverse i.e (closest largest number)
            !   if cant find them the min value is the target node
    *   8.  Once everything is moved stack a should have almost sorted list,
    *       check from the top until you find a unsorted node, 
    *       if its above the median you do rotate(a) else you do rev-rotate(a)
    
    &       tadaaaa!!!
*/

/*
    
&       Pseudo code:
    
*    1.	Declare pointers to two data structures/linked lists, one for stack a and another for `b`
!        Set both pointers to NULL to avoid undefined behaviour and indicate we're starting with empty stacks
*    2.	Handle input count errors. Argument count must be 2 or more, and the second input must not be empty
!        If input errors, return error
*    3.	Handle both cases of input, whether a variable number of command line arguments, or as a string
!        If the input of numbers is as a string, call `split()` to split the substrings
*    4.	Initialize stack `a` by appending each input number as a node to stack `a`
^      Handle integer overflow, duplicates, and syntax errors, e.g. input must only contain digits, or signs
!          If errors found, free stack `a` and return error
^      Check for each input, if it is a long integer
!          If the input is a string, convert it to a long integer
*    5.	Append the nodes to stack `a`
*    6.	Check if stack a` is sorted
!        If not sorted, implement our sorting algorithm
*    7.	Check for 2 numbers
!        If so, simply swap the numbers
*    8.	Check for 3 numbers
!        If so, implement our simple `sort three` algorithm
*    9.	Check if the stack has more than 3 numbers
!        If so, implement TURK ALGORITHM
*/

void push_swap(t_stack *stk_a,t_stack *stk_b, int list_size)
{
        int target_node = 0;
        int stk_len = stk_length(stk_a);
        
     
        
        if(list_size == 2)
                sa(stk_a);
	if(stk_len == 3)
		sort_three(stk_a);
        push_a(stk_a, stk_b);
        if(stk_len > 3)
                {
                        push_a(stk_a, stk_b);
                        target_node = find_target(stk_a, stk_b); 
                        printf("%d", target_node);
                        printf("%d", list_size);  
                        //!     do the thing with the thing that does the thing
                }
	
}

void sort_three(t_stack *stk)
{
	t_node *max_value;

	max_value = find_max(stk);
        if(max_value == NULL)
                return;
        if((max_value == stk->head))
                rotate_stack(stk);
        else if ((max_value == stk->head->previous))
                rev_rotate(stk);
        else if (stk->head->content > stk->head->previous->content)
                sa(stk);
	
	//*      if max is at top: ra
	//*      if max is at the the head->previous: rev_rot
	//*      stk->head->content > stk->head->previous->content
	//*      sa	
}

int stk_length(t_stack *stk)
{
        t_node *temp;
        int     ctr;

        ctr = 0;

        if(!stk || !stk->head)
                return(0);
        temp = stk->head;
        while(temp)
        {
                ctr++;
                temp = temp->previous;
        }
        return(ctr);
}

int find_target(t_stack *stk_a, t_stack *stk_b)
{
        t_node *targetnode;
        t_node *current_a;
        t_node *current_b;
        int result;

        result = 0;
        current_a = stk_a->head;
        current_b = stk_b->head;
        
        targetnode = malloc(sizeof(t_node));
        if((targetnode == NULL))
                return(0);
        while(current_b != NULL)
        {
                if(current_b->content < current_a->content && (targetnode != NULL || current_b->content > targetnode->content))
                {
                        current_b = targetnode;
                }
                current_b = current_b->previous;       
        }
                current_a = current_a->previous;
                result = targetnode->content;
                free(targetnode);
                return(result);
}

