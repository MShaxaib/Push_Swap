
#include "push_swap.h"

t_node  *find_smaller_target(t_node *current_a, t_node **targets, t_stack *b)
{
    t_node  *target;
    t_node  *current_b;
    int     i;

    /*
        1) set current b to the head of stack b
        2) set target to NULL
        while (current b != NULL)
        {
            if(current_b->content < current_a->content && (targetnode != NULL || current_b->content > targetnode->content))
                current_b = targetnode;
            current_b = current_b->previous;
        }
        if (the target is still null)
            return the max element
        return target
    */
    return (target);
}
/*
    steps:
    1) find targets of a 

*/
void    mechanical_turk(t_stack *a, t_stack *b)
{
    // find target
    t_node  *current_a;
    t_node  **targets;
    int     *weights;
    int     i;

    i = 0;
    //malloc for targets
    targets = (t_node **)malloc(stk_length(a) * (sizeof(t_node *)));
    //malloc for weights
    /*
        loop through a with c        urrent a
        {
            find a target for every element in a:
            targets[i] = find smaller target;
            i ++;
            current a = current a previous
        }
    
    
    */    
}
