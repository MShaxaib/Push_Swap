/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 05:34:44 by codespace         #+#    #+#             */
/*   Updated: 2024/01/21 09:24:55 by codespace        ###   ########.fr       */
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
// int word_length(char *argv, char delim)
// {
// 	int i;
// 	int word_len;
	
// 	i = -1;
// 	word_len = 0;
// 	while(argv[++i] && argv[i] != delim)
// 		word_len++;
// 	return (word_len);	
// }

// int word_count(char *argv, char delim)
// {
// 	int i;
// 	int j;
// 	int ctr;

// 	i = 0;
// 	ctr = 0;

// 	while(argv[i])
// 	{
// 		if(argv[i] != delim)
// 		{
// 			j = 1;
// 			while(argv[j] != delim && argv[i])
// 				j++;
// 			i = j;
// 			ctr++;
// 		}
// 		if(argv[i])
// 			i++;
// 	}
// 	return(ctr);
// }

// void free_split(char **splitted_list, int word_ctr)
// {
// 	while (word_ctr--)
// 		free(splitted_list[word_ctr]);
// 	free(splitted_list);
// }

// char **split(char *argv, char delim)
// {
// 	int i;
// 	int j;
// 	int word_ctr;
// 	char **splited_list;

// 	i = -1;
// 	j = 0;
	
// 	if(!argv)
// 		return(NULL);
// 	word_ctr = word_count(argv, delim);
// 	splited_list = (char **)malloc(sizeof(char *) * (word_ctr + 1));
// 	if(!splited_list)
// 		return(NULL);
// 	splited_list[word_ctr] = NULL;
// 	while(++i < word_ctr)
// 	{
// 		while (argv[j] == delim)
// 			j++;
// 		splited_list[i] = ft_substr(argv, j, word_length((argv + j), delim));
// 		if(!splited_list[i])
// 			return(free_split(splited_list, word_ctr), NULL);
// 		j += word_length((argv + 1), delim);
// 	}
// 	return(splited_list);		
// }
