/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:22:41 by codespace         #+#    #+#             */
/*   Updated: 2024/02/18 12:38:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H

# define FT_STACK_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Stacks and structs

typedef struct node
{
	int			content;
	int			index;
	int			weight;
	struct node	*target;
	struct node	*previous;
}				t_node;

typedef struct stack
{
	t_node		*head;
	t_node		*tail;
	int			rot_ctr;
	int			rev_rot_ctr;
}				t_stack;

// STACK INITIAZATION
t_stack			*create_stack_a(int *num_list, int list_size);
t_stack			*create_stack_b(t_stack *stk_a, int list_size);
t_stack			*init_stack(void);

// STACK OPERATIONS
void			stk_push(t_stack *stk, int value);
void			stk_pop(t_stack *stk);

// STACK MOVES
void			sa(t_stack *stk_a, int c_flag);
void			sb(t_stack *stk_b, int c_flag);
void			ss(t_stack *stk_a, t_stack *stk_b, int c_flag);
void			rotate_stack(t_stack *stk, char c);
void			push_head(t_stack *dest, t_stack *src, char flag);
void			rev_rotate(t_stack *stk, char c);
void			rrr(t_stack *stk_a, t_stack *stk_b, int c_flag);
void			rr(t_stack *stk_a, t_stack *stk_b, int c_flag);

void			update_index(t_stack *stk);
int				stk_length(t_stack *stk);

// destroying
void			destroy_stacks(t_stack *a, t_stack *b, int list_size);
void			ft_destroy(t_stack *stk);
int				ft_is_empty(t_stack *stk);

// test
void			pstk(t_stack *stk);

#endif