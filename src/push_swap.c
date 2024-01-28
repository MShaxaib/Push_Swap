/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:10:17 by codespace         #+#    #+#             */
/*   Updated: 2024/01/28 11:56:29 by codespace        ###   ########.fr       */
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
    
*    Declare pointers to two data structures/linked lists, one for stack a and another for `b`
!        Set both pointers to NULL to avoid undefined behaviour and indicate we're starting with empty stacks
*    Handle input count errors. Argument count must be 2 or more, and the second input must not be empty
!        If input errors, return error
*    Handle both cases of input, whether a variable number of command line arguments, or as a string
!        If the input of numbers is as a string, call `split()` to split the substrings
*    Initialize stack `a` by appending each input number as a node to stack `a`
^      Handle integer overflow, duplicates, and syntax errors, e.g. input must only contain digits, or signs
!          If errors found, free stack `a` and return error
^      Check for each input, if it is a long integer
!          If the input is a string, convert it to a long integer
*    Append the nodes to stack `a`
*    Check if stack a` is sorted
!        If not sorted, implement our sorting algorithm
*    Check for 2 numbers
!        If so, simply swap the numbers
*    Check for 3 numbers
!        If so, implement our simple `sort three` algorithm
*    Check if the stack has more than 3 numbers
!        If so, implement TURK ALGORITHM
    

*/