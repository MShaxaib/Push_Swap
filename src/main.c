/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 06:45:24 by codespace         #+#    #+#             */
/*   Updated: 2024/02/16 19:44:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*num_list;
	int		list_size;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		num_list = validator(++argv, 1, &list_size);
	else
		num_list = validator(getcharlist(++argv, argc, &list_size), argc - 1,
				&list_size);
	if (!num_list)
		return (0);
	if (num_list != NULL)
	{
		if (is_sorted(num_list, list_size) == 1)
			return (free(num_list), 0);
		a = create_stack_a(num_list, list_size);
		if (list_size == 2)
			sa(a);
		if (list_size == 3)
			sort_three(a);
		if (list_size > 3)
		{
			b = create_stack_b(a, list_size);
			push_swap(a, b);
			destroy_stacks(&a, &b, list_size);
		}
	}
	return (0);
}
