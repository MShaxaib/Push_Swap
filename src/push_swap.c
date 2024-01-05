/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:10:17 by codespace         #+#    #+#             */
/*   Updated: 2024/01/05 13:47:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    int j;
    char *char_list;
    char **s;
    i = 1;  

    if (argc > 1)
    {
        while (argv[i] != NULL)
        {
            j = 0;
            if (!ft_isalnum(argv[i][j]))
            {
                fprintf(stderr, "Error: input not valid\n");
                return 1; 
            }
            char_list = argv[i];
            s = ft_split(char_list, ' ');
            while (s[j] != NULL)
            {
                printf("%s\n", s[j]);
                j++;
            }
            free(s);
            i++;
        }
    }
    return 0;
}


