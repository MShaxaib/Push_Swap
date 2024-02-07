
#include "push_swap.h"

t_node  *find_smaller_target(t_node *current_src, t_stack *b)
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
		if((current_b->content < current_src->content) &&
			((target == NULL) || (current_b->content > target->content)))
			target = current_b;
		current_b = current_b->previous;
	}
	if(target == NULL)
		return(find_max(b));
	
	return(target);
}

/// @brief Calculates the number of moves it takes to move each node in src and its target in dest to the top of their stacks (need to optmise the calculation depending on if the node and target node are above or below the median)
/// @param src_idx src node's index
/// @param target_idx target nodes index
/// @param src_stk Stack A
/// @param target_stk Stack B
/// @return 
int calculate_cost(int src_idx, int target_idx, t_stack *src_stk, t_stack *target_stk)
{
	int total_cost;
	double src_pos;
	double target_pos;
	int		src_weight;
	int		target_weight;

	src_weight = 0;
	target_weight = 0;
	total_cost = 0;
	src_pos = (float)src_idx / (float)(stk_length(src_stk));
	target_pos = (float)target_idx / (float)(stk_length(target_stk));
	printf("src pos is: %f\n", src_pos);
	printf("target pos is: %f\n", target_pos);
	if (src_idx != 0)
	{
		if (src_pos <= 0.5)
			src_weight = src_idx;
		else
			src_weight = stk_length(src_stk) - src_idx;
	}
	if(target_idx != 0)
	{
		if (target_pos <= 0.5)
			target_weight = target_idx;
		else
			target_weight = stk_length(target_stk) - target_idx;
	}
	total_cost = src_weight + target_weight;
	return (total_cost);
}

t_node *smallest_weight(t_stack *stk)
{
	t_node *iter;
	t_node *min_node = NULL;

	iter = stk->head;
	min_node = iter;
	while(iter != NULL)
		{
			if(iter->weight < min_node->weight)
				min_node = iter;
			iter = iter->previous;
		}
	return(min_node);
}

/// @brief implementation of the mechanical turk algorithm
/// @param a (to be changed to source) the source stack to be pushed from
/// @param b (to be changed to dest) the destination to push to
void    mechanical_turk(t_stack *src_stk, t_stack *dest_stk, int src_is_a)
{
	t_node  *current_src;
	t_node  *current_dest;
	t_node *min_node;
	current_src = src_stk->head;
	current_dest = dest_stk->head;

//!----------------------------------------------------------------------------------------------------------------
	printf("<----------STACKS---------->\n");
	printf("---stack A---\n");

	while (current_src != NULL)
		{
			printf("the node %d\n", current_src->content);
			current_src = current_src->previous;
		}
		printf("\n---stack B---\n");

	while (current_dest != NULL)
		{
			printf("the node %d\n", current_dest->content);
			current_dest = current_dest->previous;
		}
	current_src = src_stk->head;
//!----------------------------------------------------------------------------------------------------------------
	printf("\n<----------Debug---------->\n");
		while(current_src != NULL)
		{
			current_src->target = find_smaller_target(current_src, dest_stk);
			current_src-> weight = calculate_cost(current_src->index, current_src->target->index, src_stk, dest_stk);
			printf("for node %d :		", current_src->content);
			printf("at index: %d\n", current_src->index);
			printf("the target is %d		", current_src->target->content);
			printf("the weight is %d\n", current_src->weight);
			printf("------------------------------------------------------\n");
			current_src = current_src->previous;
		}
	min_node = smallest_weight(src_stk);
	put_to_top(min_node, src_stk, dest_stk, src_is_a);
	if (src_is_a == 1)
		push_b(src_stk, dest_stk);

	current_src = src_stk->head;
	current_dest = dest_stk->head;

//!----------------------------------------------------------------------------------------------------------------
	printf("<----------STACKS---------->\n");
	printf("---stack A---\n");

	while (current_src != NULL)
		{
			printf("the node %d\n", current_src->content);
			current_src = current_src->previous;
		}
		printf("\n---stack B---\n");

	while (current_dest != NULL)
		{
			printf("the node %d\n", current_dest->content);
			current_dest = current_dest->previous;
		}
	current_src = src_stk->head;




	//printf("\nMin node values -------\nContent: %d\nSrc Index: %d\nWeight: %d\nTarget : %d\nTargets index: %d\n ", min_node->content, min_node->index, min_node->weight, min_node->target->content, min_node->target->index);
}
