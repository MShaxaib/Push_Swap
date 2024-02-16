/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:10:22 by codespace         #+#    #+#             */
/*   Updated: 2024/02/16 19:44:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *num_list, int c)
{
	int	i;

	i = 0;
	while (i < c - 1)
	{
		if (num_list[i] > num_list[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// frees and prints error
void	print_error(char **str, int *num_list)
{
	if (str)
		free(str);
	if (num_list)
		free(num_list);
	write(2, "Error\n", 6);
}

int	check_duplicates(int *num_list, int *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*c) - 1)
	{
		j = i + 1;
		while (j < (*c))
		{
			if (num_list[i] == num_list[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*convert_numlist(char **str, int *c)
{
	int	*nums;
	int	i;

	i = 0;
	nums = malloc((*c) * sizeof(int));
	if (!nums)
		return (NULL);
	while (i < (*c))
	{
		if (ft_isnum(str[i]) == 1)
		{
			free(nums);
			return (NULL);
		}
		if (ft_atol(str[i]) > INT_MAX || ft_atol(str[i]) < INT_MIN)
			return (free(nums), NULL);
		nums[i] = ft_atol(str[i]);
		i++;
	}
	return (nums);
}

/// @brief Velidates the arguments, splits it.
/// @param str argv
/// @param joined flag to check if the input is in 1 argument or no
/// @param listsize size of the arguments
/// @return char list

int	*validator(char **str, int joined, int *listsize)
{
	char	**char_list;
	int		*num_list;

	num_list = 0;
	if (joined == 1)
		char_list = ft_split(*str, listsize);
	else
	{
		char_list = str;
		if (char_list == NULL)
			return (print_error(char_list, num_list), NULL);
	}
	num_list = convert_numlist(char_list, listsize);
	if (!num_list)
		return (print_error(char_list, num_list), NULL);
	if (check_duplicates(num_list, listsize))
		return (print_error(char_list, num_list), NULL);
	return (free_split(char_list), num_list);
}
