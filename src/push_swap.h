/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:16:44 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/19 13:10:59 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../utils/utils.h"
# include "../stacks/ft_stack.h"
# include "../getnextline/get_next_line.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	push_swap(t_stack *stk_a, t_stack *stk_b);
//

int		*validator(char **str, int joined, int *listsize);
int		is_sorted(int *num_list, int c);
char	**getcharlist(char **argv, int argc, int *list_size);
void	sort_three(t_stack *stk);

//
int		find_target(t_stack *stk_a, t_stack *stk_b);
t_node	*find_max(t_stack *stk);
t_node	*find_min(t_stack *stk);

// Mechanical Turk
void	mechanical_turk(t_stack *a, t_stack *b, int src_is_a);
t_node	*find_smaller_target(t_node *current_a, t_stack *b);
t_node	*find_larger_target(t_node *current_src, t_stack *a);
int		cal_cos(int src_idx, int target_idx, t_stack *src_stk,
			t_stack *target_stk);
void	put_to_top(t_stack *src_stk, t_stack *dest_stk, int src_is_a);
t_node	*smallest_weight(t_stack *stk);
void	set_rotations(t_node *min_node, t_stack *src_stk, t_stack *dest_stk);

// SORT
void	sort_stack(t_stack *stk);
void	not_sorted(t_stack *stk, t_node *iter);
void	read_moves(t_stack *src_stk, t_stack *dest_stk);

#endif