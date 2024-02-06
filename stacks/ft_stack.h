/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:22:41 by codespace         #+#    #+#             */
/*   Updated: 2024/02/06 07:58:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H

#define FT_STACK_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

//Stacks and structs

typedef struct node
{
    int content;
    int index;
    struct node *previous;
}   t_node;

typedef struct stack
{
    t_node *head;
    t_node *tail;
    
}   t_stack;


// STACK INITIAZATION
t_stack *create_stack_a(int *num_list, int list_size);
t_stack *create_stack_b(t_stack *stk_a, int list_size);
t_stack *init_stack(void);

// STACK OPERATIONS
t_stack *stk_push(t_stack *stk, int value);
t_stack *stk_pop(t_stack *stk);

// STACK MOVES
void sa(t_stack *stk_a);
void sb(t_stack *stk_b);
void ss(t_stack *stk_a, t_stack *stk_b);
void rotate_stack(t_stack *stk, char c);
void push_a(t_stack *stk_a, t_stack *stk_b);
void push_b(t_stack *stk_a, t_stack *stk_b);
void rev_rotate(t_stack *stk, char c);
void rrr(t_stack *stk_a, t_stack *stk_b);


void	update_index(t_stack *stk);
int stk_length(t_stack *stk);

//test

void pstk(t_stack *stk);





#endif