
#include "push_swap.h"

t_node  *find_smaller_target(t_node *current_a, t_node **targets, t_stack *b, int i)
{
    t_node  *target;
    t_node  *current_b;
    int     i;

    current_b = b->head;
    target = NULL;

    while(current_b != NULL)
    {
        if((current_b->content < current_a->content &&((target != NULL) || (current_b->content > target->content))))
            current_b = target;
        current_b = current_b->previous;
    }
    targets[i] = target;
    if(target = NULL)
        return(find_max(b));
    
    return(target);

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
    weights = malloc(sizeof(int));
    //malloc for weights

    while(current_a != NULL)
    {
        targets[i] = find_smaller_target(current_a, targets, b);
        i++;
        current_a = current_a->previous;
    }   
}
