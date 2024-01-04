/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 05:34:44 by codespace         #+#    #+#             */
/*   Updated: 2024/01/04 05:53:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

static int	word_length(char const *src, char delim)
{
	int	i;
		int	word_len;

	i = -1;
	word_len = 0;
	while (src[++i] && src[i] != delim)
		word_len++;
	return (word_len);
}

static int	word_count(char const *src, char delim)
{
	int	i;
	int	j;
	int	word_ctr;

	i = 0;
	word_ctr = 0;
	while (src[i])
	{
		if (src[i] != delim)
		{
			j = i;
			while (src[j] != delim && src[j])
				j++;
			i = j;
			word_ctr++;
		}
		if (src[i])
			i++;
	}
	return (word_ctr);
}

static char	**free_split(char **split, int word_ctr)
{
	while (word_ctr--)
		free (split[word_ctr]);
	free (split);
	return (NULL);
}

char	**ft_split(char const *src, char delim)
{
	int		i;
	int		j;
	int		word_ctr;
	char	**split;

	i = -1;
	j = 0;
	if (!src)
		return (NULL);
	word_ctr = word_count(src, delim);
	split = (char **)malloc(sizeof(char *) * (word_ctr + 1));
	if (!split)
		return (NULL);
	split[word_ctr] = NULL;
	while (++i < word_ctr)
	{
		while (src[j] == delim)
			j++;
		split[i] = ft_substr(src, j, word_length((src + j), delim));
		if (!split[i])
			return (free_split(split, i));
		j += word_length((src + j), delim);
	}
	return (split);
}


int	main(void)
{
	char str[] = ",,,,,,hell o,,,,,wor ld,i s,st upid,,,,,";
	char **s = ft_split(str, ',');
	int i = 0;
	while (s[i])
		printf("|%s|\n", s[i++]);
	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (0);
}