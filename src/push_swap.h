/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:16:44 by codespace         #+#    #+#             */
/*   Updated: 2024/01/27 12:41:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAB_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

#include "../Utils/Utils.h"
#include "../stacks/ft_stack.h"

int *validator(char **str, int joined, int *listsize);
int is_sorted(int *num_list, int c);
char **getcharlist(char **argv, int argc, int *list_size);

#endif