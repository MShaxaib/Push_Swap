/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:16:37 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/17 23:10:27 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	checkandsend(int *num_list, int list_size)
{
	t_stack	*a;
	t_stack	*b;
	char	*list;

	
	if (num_list != NULL)
	{
		if (is_sorted(num_list, list_size) == 1)
			return (free(num_list), 0);
		a = create_stack_a(num_list, list_size);
		b = create_stack_b(a, list_size);
		list = get_next_line(0);
		if(!list)
			return(0);
		while(list)
		{
			if (read_moves(a, b, list))
				return 1;
			list = get_next_line(0);
		}
			destroy_stacks(&a, &b, list_size);
	}
	return(0);
}

int	main(int argc, char **argv)
{
	int		*num_list;
	int		list_size;


	if (argc == 1)
		return (0);
	else if (argc == 2)
		num_list = validator(++argv, 1, &list_size);
	else
		num_list = validator(getcharlist(++argv, argc, &list_size), argc - 1,
				&list_size);
	if (!num_list)
		return (0);
	if(checkandsend(num_list, list_size) == 1)
	{
		printf("Error\n");
		return(1);
	}
	return (0);
}

int read_moves(t_stack *src_stk, t_stack *dest_stk, char *list)
{
	if(!ft_strcmp(list, "sa\n"))
		sa(src_stk);
	else if(!ft_strcmp(list, "sb\n"))
		sb(dest_stk);
	else if(!ft_strcmp(list, "ss\n"))
		ss(src_stk, dest_stk);
	else if(!ft_strcmp(list, "ra\n"))
		rotate_stack(src_stk, 'a');
	else if(!ft_strcmp(list, "rb\n"))
		rotate_stack(dest_stk,'b');
	else if(!ft_strcmp(list, "rr\n"))
		rr(src_stk,dest_stk);
	else if(!ft_strcmp(list, "rra\n"))
		rev_rotate(src_stk, 'a');
	else if(!ft_strcmp(list, "rrb\n"))
		rev_rotate(dest_stk, 'b');
	else if(!ft_strcmp(list, "rrr\n"))
		rrr(src_stk,dest_stk);
	else if(!ft_strcmp(list, "pa\n"))
		push_head(src_stk,dest_stk, 'a');
	else if(!ft_strcmp(list, "pb\n"))
		push_head(src_stk,dest_stk, 'b');
	else
		return(free(list), 1);
	return(free(list), 0);
}
