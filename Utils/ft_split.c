/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 05:34:44 by codespace         #+#    #+#             */
/*   Updated: 2024/02/16 13:56:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.h"

int	set_end(char const *s, int begin)
{
	int	end;

	end = begin;
	while (s[end] && s[end] != ' ')
		end++;
	return (end);
}

int	get_num_ctr(char *arg)
{
	int	i;
	int	ctr;

	i = 0;
	ctr = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == ' ')
			i++;
		else
		{
			ctr++;
			while (arg[i] != '\0' && arg[i] != ' ')
				i++;
		}
	}
	return (ctr);
}

void	free_split(char **p)
{
	int	j;

	j = 0;
	while (p[j] != NULL)
	{
		free(p[j]);
		p[j] = NULL;
		j++;
	}
	free(p);
}

char	**fill_list(char *arg, int ctr)
{
	unsigned int	begin;
	unsigned int	end;
	int				i;
	char			**char_list;

	i = 0;
	begin = 0;
	end = 0;
	char_list = malloc((ctr + 1) * sizeof(char *));
	if (char_list == NULL)
		return (NULL);
	while (i < ctr)
	{
		while (arg[begin] != '\0' && arg[begin] == ' ')
		{
			begin++;
		}
		end = set_end(arg, begin);
		char_list[i] = ft_substr(arg, begin, (size_t) end - begin);
		begin = end;
		i++;
	}
	char_list[i] = NULL;
	return (char_list);
}

char	**ft_split(char *arg, int *list_size)
{
	char	**char_list;

	if (arg == NULL)
		return (0);
	*list_size = get_num_ctr(arg);
	char_list = fill_list(arg, *list_size);
	return (char_list);
}
