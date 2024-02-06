
#include "push_swap.h"

t_node  *find_smaller_target(t_node *current_a, t_stack *b)
{
	t_node  *target;
	t_node  *current_b;

	current_b = b->head;
	while(current_b != NULL)
	{
		// printf("the current b is : %d\n", current_b->content);
		current_b = current_b->previous;
	}
	target = NULL;
	current_b = b->head;
	while(current_b)
	{
		if((current_b->content < current_a->content) &&
			((target == NULL) || (current_b->content > target->content)))
			target = current_b;
		current_b = current_b->previous;
	}
	if(target == NULL)
		return(find_max(b));
	
	return(target);
}

int calculate_cost(int src_idx, int target_idx, t_stack *src_stk, t_stack *target_stk)// , t_stack *dest_stk
{
	int total_cost;
	double src_weight;
	double target_weight;

	src_weight = (float)src_idx / (float)(stk_length(src_stk));
	target_weight = (float)target_idx / (float)(stk_length(target_stk));
	
	
	total_cost = 0;
	
	if(!(src_idx == 0 && target_idx == 0))
	{
		if(src_weight <= 0.5 )
			src_weight = src_idx;
		else if (src_weight > 0.5)
			src_weight = stk_length(src_stk) - src_idx;
		if(target_weight <= 0.5)
			target_weight = target_idx;
		else if (target_weight > 0.5)
			target_weight = target_idx;
	}
	total_cost = src_weight + target_weight;

	printf("total cost is : %d\n", total_cost);
	printf("index of source = %d and index of it's target = %d\n",src_idx, target_idx);
	printf("----------------------------------\n");
return(total_cost);

}

/// @brief implementation of the mechanical turk algorithm
/// @param a (to be changed to source) the source stack to be pushed from
/// @param b (to be changed to dest) the destination to push to
void    mechanical_turk(t_stack *a, t_stack *b)
{
	t_node  *current_a;
	t_node  *current_b;
	t_node  **targets;
	int     *cost;
	int     i;
	cost = 0;
	current_a = a->head;
	current_b = b->head;

//!----------------------------------------------------------------------------------------------------------------
	printf("<----------STACKS---------->\n");
	i = 0;
	targets = (t_node **)malloc(stk_length(a) * (sizeof(t_node *)));
	cost = (int *) malloc(stk_length(a) * (sizeof(int)));

	printf("---stack A---\n");

	while (current_a != NULL)
	{
		printf("the node %d\n", current_a->content);
		current_a = current_a->previous;
	//	i ++;
	}
		printf("\n---stack B---\n");

	while (current_b != NULL)
	{
		printf("the node %d\n", current_b->content);
		current_b = current_b->previous;
	//	i ++;
	}
// printf("------------------------------------------------------\n");
	current_a = a->head;
//!----------------------------------------------------------------------------------------------------------------
	printf("\n<----------Debug---------->\n");
	while(current_a != NULL)
	{
		targets[i] = find_smaller_target(current_a, b);
		cost[i] = calculate_cost(current_a->index,targets[i]->index, a,b); //, b
		i++;
		current_a = current_a->previous;
	}
		current_a = a->head;
		i = 0;






	while (current_a)
	{
		printf("the node %d        has target %d\n", current_a->content, targets[i]->content);
		current_a = current_a->previous;
		i ++;
	}
}


