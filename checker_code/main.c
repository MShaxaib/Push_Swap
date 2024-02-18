/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:16:37 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/18 20:18:05 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	is_stk_sorted(t_stack *stk)
{
	t_node	*itr;

	if (!stk || !stk->head)
		return (0);
	itr = stk->head;
	while (itr->previous)
	{
		if (itr->content > itr->previous->content)
			return (0);
		itr = itr->previous;
	}
	return (1);
}

int	execute_moves(t_stack *src_stk, t_stack *dest_stk, char *list)
{
	if (!ft_strcmp(list, "sa\n"))
		sa(src_stk, 0);
	else if (!ft_strcmp(list, "sb\n"))
		sb(dest_stk, 0);
	else if (!ft_strcmp(list, "ss\n"))
		ss(src_stk, dest_stk, 0);
	else if (!ft_strcmp(list, "ra\n"))
		rotate_stack(src_stk, '0');
	else if (!ft_strcmp(list, "rb\n"))
		rotate_stack(dest_stk, '0');
	else if (!ft_strcmp(list, "rr\n"))
		rr(src_stk, dest_stk, 0);
	else if (!ft_strcmp(list, "rra\n"))
		rev_rotate(src_stk, '0');
	else if (!ft_strcmp(list, "rrb\n"))
		rev_rotate(dest_stk, '0');
	else if (!ft_strcmp(list, "rrr\n"))
		rrr(src_stk, dest_stk, 0);
	else if (!ft_strcmp(list, "pb\n"))
		push_head(dest_stk, src_stk, 'n');
	else if (!ft_strcmp(list, "pa\n"))
		push_head(src_stk, dest_stk, 'n');
	else
		return (free(list), 1);
	return (free(list), 0);
}

void	read_moves(t_stack *src_stk, t_stack *dest_stk)
{
	char	*list;

	list = get_next_line(0);
	while (list != NULL)
	{
		if (execute_moves(src_stk, dest_stk, list))
		{
			write(1, "Error\n", 7);
			return ;
		}
		list = get_next_line(0);
	}
	if (is_stk_sorted(src_stk) == 1 && stk_length(dest_stk) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	int		*num_list;
	int		list_size;
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	else if (ac == 2)
		num_list = validator(++av, 1, &list_size);
	else
		num_list = validator(getcharlist(++av, ac, &list_size), ac - 1,
				&list_size);
	if (num_list)
	{
		a = create_stack_a(num_list, list_size);
		b = init_stack(list_size);
		read_moves(a, b);
		destroy_stacks(a, b, list_size);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
