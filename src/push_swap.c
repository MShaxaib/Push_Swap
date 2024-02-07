/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:10:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/07 10:21:41 by codespace        ###   ########.fr       */
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

void sort_three(t_stack *stk)
{
	t_node *max_value;

	max_value = find_max(stk);
	if((max_value == stk->head))
		rotate_stack(stk, 'a');
	else if ((max_value == stk->head->previous))
		rev_rotate(stk, 'a');
	if (stk->head->content > stk->head->previous->content)
		sa(stk);
	update_index(stk);
}
void push_swap(t_stack *stk_a,t_stack *stk_b)
{
	int i = 0;
		while (stk_length(stk_a) > 3)
		{
			printf("\n*-*-*-*-*-**-*-**-*-**-*-**ITERATION %d -*-**-*-**-*-**-*-**-*-**-*-**-*-**-*-*\n",i++);
			mechanical_turk(stk_a, stk_b, 1);
			//call mechanical turk;
			//push from a to b;
		}
	
		sort_three(stk_a);
		// while (size of b is 0)
		// {
		// 	mechanical_turk(stk_b, stk_a, 0);
		// }
		t_node *current_src= stk_a->head;
		t_node *current_dest= stk_b->head;
	printf("\nstack  A after the sort in place\n");
	while (current_src != NULL)
		{
			printf("the node %d		has index %d		with target node %d			with the weight of %d		\n", current_src->content, current_src->index, current_src->target->content, current_src->weight);
			current_src = current_src->previous;
		}
	printf("\nstack  B after the sort in place\n");

	while (current_dest != NULL)
		{
			printf("the node %d\n", current_dest->content);
			current_dest = current_dest->previous;
		}
		//target_node = find_target_smaller(stk_a, stk_b);
		//!     do the thing with the thing that does the thing
}
