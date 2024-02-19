/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 05:43:43 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/19 13:12:11 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char *argv, int *list_size);
size_t	ft_strlen(char const *str);
int		ft_isnum(char *a);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
char	*ft_join(int argc, char **argv);
void	free_split(char **p);
int		ft_strcmp(char *s1, char *s2);

#endif