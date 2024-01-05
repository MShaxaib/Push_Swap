/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 05:43:43 by codespace         #+#    #+#             */
/*   Updated: 2024/01/05 04:28:06 by codespace        ###   ########.fr       */
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
char	**ft_split(char const *src, char delim);
size_t	ft_strlen(char const *str);
int     ft_isalnum(char a);




#endif