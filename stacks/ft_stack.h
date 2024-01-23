/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:22:41 by codespace         #+#    #+#             */
/*   Updated: 2024/01/22 05:44:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H

#define FT_STACK_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
/*


Stacks and structs

*/
typedef struct node
{
    int content;
    int index;
    struct node *previous;
    struct node *next;
}   t_node;

typedef struct stack
{
    t_node *head;
    t_node *tail;
    
}   t_stack;


t_stack *create_stack_a(int *num_list, int list_size);
t_stack *init_stack(void);








#endif