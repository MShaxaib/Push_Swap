/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:22:41 by codespace         #+#    #+#             */
/*   Updated: 2024/01/19 15:25:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H

#define FT_STACK_H

/*


Stacks and structs

*/
typedef struct node
{
    int content;
    int index;
    struct node *previous;
    struct node *next;
}   t_node;

typedef struct stack
{
    t_node *head;
    t_node *tail;
    
}   t_stack;









#endif