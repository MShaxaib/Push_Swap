/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 05:43:43 by codespace         #+#    #+#             */
/*   Updated: 2024/02/16 13:43:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
char    **ft_split(char *argv, int *list_size);
size_t	ft_strlen(char const *str);
int     ft_isnum(char *a);
int	    ft_atoi(const char *str);
long	ft_atol(const char *str);
char    *ft_join(int argc, char **argv);
void	free_split(char **p);

#endif