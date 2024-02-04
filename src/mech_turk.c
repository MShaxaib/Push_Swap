
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
}

int calculate_cost(t_node *target, t_stack *stk, int index)
{
	/*
	 ^	 check if the target node is at the same index as the src
	 ^ 		if(yes) then just push A -> B
	 ^		else check if its above or below the median 
	 ^		if(above)
	 ^			then keep doing RB until it reaches the top
	 &			cost = index 
	 ^		if(below)
	 ^			keep doing RRB until it reaches the top
	 &			cost = index - length
	 ! 		once the target node reaches the top then we have to move the src node to the top as well
	 ^ 		same thing as above for SRC stack but it will be simpler since there are only 3 elements

	&		everytime we do a move we count++ and thats the cost
	*/

}

void    mechanical_turk(t_stack *a, t_stack *b)
{
	t_node  *current_a;
	t_node  **targets;
	int     *cost;
	int     i;

	i = 0;
	targets = (t_node **)malloc(stk_length(a) * (sizeof(t_node *)));
	cost = malloc(sizeof(int));

	while(current_a != NULL)
	{
		targets[i] = find_smaller_target(current_a, targets, b, i);
		i++;
		current_a = current_a->previous;
	}
}
