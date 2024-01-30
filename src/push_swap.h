/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:16:44 by codespace         #+#    #+#             */
/*   Updated: 2024/01/30 20:11:41 by mshazaib         ###   ########.fr       */
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

int *validator(char **str, int joined, int *listsize);
int is_sorted(int *num_list, int c);
char **getcharlist(char **argv, int argc, int *list_size);
void sort_three(t_stack *stk);

//

t_node *find_max(t_stack *stk);
t_node *find_min(t_stack *stk);

#endif