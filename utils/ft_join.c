/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:23:25 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/19 20:09:05 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	skip_spaces(char **argv, int i, int j)
{
	while ((argv[i][j] == ' ') && argv[i][j] != '\0')
		j++;
	return (j);
}

char	*copytolist(char **argv, int argc, int list_len)
{
	int		i;
	int		j;
	int		y;
	char	*list;

	i = 0;
	j = -1;
	list = malloc((list_len) * sizeof(char));
	if (!list)
		return (NULL);
	while (++j < argc)
	{
		y = -1;
		while (argv[j][++y])
		{
			y = skip_spaces(argv, j, y);
			while (argv[j][y] && argv[j][y] != ' ')
				list[i++] = argv[j][y++];
			list[i++] = ' ';
			if (!argv[j][y])
				y--;
		}
	}
	list[--i] = '\0';
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
			while (argv[i][j] != ' ' && argv[i][j] != '\0')
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
	return (joined);
}
