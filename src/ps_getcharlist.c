/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getcharlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:30:42 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/19 14:36:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief counts for all the non-space characters in the string
/// @param args raw user input
/// @return number of non-space characters.

int	trim_counter(char *args)
{
	int	index;
	int	spaces;
	int	numbers;

	index = 0;
	spaces = 0;
	numbers = 0;
	while (args[index] != '\0')
	{
		if (args[index] == ' ' || (args[index] >= 9 && args[index] <= 13))
		{
			spaces++;
			index++;
		}
		else
		{
			while ((args[index] != ' ' && !(args[index] >= 9
						&& args[index] <= 13)) && args[index] != '\0')
				index++;
			numbers++;
		}
	}
	if (spaces == index)
		return (-1);
	return (numbers);
}

int	num_count(int argc, char **argv)
{
	int	ctr;
	int	index;
	int	number;

	ctr = 0;
	index = 0;
	number = 0;
	while (index < argc - 1)
	{
		number = trim_counter(argv[index]);
		if (number == -1)
			return (-1);
		ctr = ctr + number;
		index++;
	}
	return (ctr);
}

char	**getcharlist(char **argv, int argc, int *list_size)
{
	char	**char_list;
	char	*joined;

	char_list = NULL;
	joined = NULL;
	*list_size = num_count(argc, argv);
	if (*list_size == -1)
		return (NULL);
	joined = ft_join(argc - 1, argv);
	char_list = ft_split(joined, list_size);
	free(joined);
	return (char_list);
}
