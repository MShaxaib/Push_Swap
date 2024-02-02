/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:16:44 by codespace         #+#    #+#             */
/*   Updated: 2024/01/31 09:43:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

#include "../Utils/Utils.h"
#include "../stacks/ft_stack.h"




void push_swap(t_stack *stk_a,t_stack *stk_b, int list_size);
//

int *validator(char **str, int joined, int *listsize);
int is_sorted(int *num_list, int c);
char **getcharlist(char **argv, int argc, int *list_size);
void sort_three(t_stack *stk);

//
int stk_length(t_stack *stk);
int find_target(t_stack *stk_a, t_stack *stk_b);
t_node *find_max(t_stack *stk);
t_node *find_min(t_stack *stk);

#endif