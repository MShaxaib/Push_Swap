/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mech_turk_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 05:08:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/07 09:48:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int above_median(src_idx, target_idx)
// {
//     int total_weight;

//     total_weight = 0;

//     if(src_idx < target_idx)
//         total_weight = src_idx + (target_idx - src_idx);
//     else if (target_idx < src_idx)
//         total_weight = target_idx  + (src_idx - target_idx);
//     return(total_weight);   
// }


/*
        0 + (1 - 0)

        0 + (1 - 0)

        1 + (2 - 1)
        

*/

/// @brief 
/// @param src 
/// @param rot if 1, rotate up, else rotate down 
void    put_a_to_top(t_stack *a, t_node *n,int rot)
{
    if (rot == 1)
        while (n->index != 0)
            rotate_stack(a, 'a');
    else
        while (n->index != 0)
            rev_rotate(a, 'a');
}
/// @brief 
/// @param src 
/// @param rot if 1, rotate up, else rotate down 
void    put_b_to_top(t_stack *b, t_node *n, int rot)
{
    if (rot == 1)
        while (n->index != 0)
            rotate_stack(b, 'b');
    else
        while (n->index != 0)
            rev_rotate(b, 'b');
}

float   calc_pos(t_stack *stk, t_node *n)
{
    return ((float)n->index / (float) stk_length(stk));
}

void put_to_top(t_node *cheapest_node, t_stack *src_stk, t_stack *dest_stk, int src_is_a)
{
    if (src_is_a == 1)
    {
        if (calc_pos(src_stk, cheapest_node) >= 0.5)
            put_a_to_top(src_stk, cheapest_node, 1);
        else
            put_a_to_top(src_stk, cheapest_node, 0);
        if (calc_pos(src_stk, cheapest_node->target) >= 0.5)
            put_b_to_top(dest_stk, cheapest_node, 1);
        else
            put_b_to_top(dest_stk, cheapest_node, 0);
    }
    else
    {
        if (calc_pos(src_stk, cheapest_node) >= 0.5)
            put_b_to_top(src_stk, cheapest_node, 1);
        else
            put_b_to_top(src_stk, cheapest_node, 0);
        if (calc_pos(src_stk, cheapest_node->target) >= 0.5)
              put_a_to_top(dest_stk, cheapest_node, 1);
        else
            put_a_to_top(dest_stk, cheapest_node, 0);
    }
}
