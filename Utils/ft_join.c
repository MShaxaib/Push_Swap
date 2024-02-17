/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:23:25 by codespace         #+#    #+#             */
/*   Updated: 2024/02/17 12:43:22 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.h"

int	skip_spaces(char **argv, int i, int j)
{
	while ((argv[i][j] == ' ') || ((argv[i][j] >= 9 && argv[i][j] <= 13)
			&& argv[i][j] != '\0'))
		j++;
	return (j);
}

void	ft_copy(char *argv, char *list, int *argv_index, int *list_index)
{
	int	lst_index;
	int	arg_index;

	lst_index = *list_index;
	arg_index = *argv_index;
	while (argv[arg_index] != '\0' && !(argv[arg_index] >= 9
			&& argv[arg_index] <= 13) && argv[arg_index] != '\0')
	{
		list[lst_index] = argv[arg_index];
		arg_index++;
		lst_index++;
		*list_index = lst_index;
		*argv_index = arg_index;
	}
}

char	*copytolist(char **argv, int argc, int list_len)
{
	int		i;
	int		j;
	int		y;
	char	*list;

	i = 0;
	j = 0;
	y = 0;
	list = malloc((list_len) * sizeof(char *));
	if (!list)
		return (NULL);
	while (j < argc)
	{
		y = 0;
		while (argv[j][y] != '\0')
		{
			y = skip_spaces(argv, j, y);
			ft_copy(argv[j], list, &y, &i);
			y = skip_spaces(argv, j, y);
			list[i++] = ' ';
		}
		j++;
	}
	list[i] = '\0';
	return (list);
}

int	ft_listlen(char **argv)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			j = skip_spaces(argv, i, j);
			while (argv[i][j] != ' ' && !(argv[i][j] >= 9 && argv[i][j] <= 13)
				&& argv[i][j] != '\0')
			{
				j++;
				len++;
			}
			len++;
		}
		i++;
	}
	return (len);
}

char	*ft_join(int argc, char **argv)
{
	char	*joined;
	int		list_len;

	list_len = ft_listlen(argv);
	joined = copytolist(argv, argc, list_len);
	joined[list_len] = '\0';
	return (joined);
}
