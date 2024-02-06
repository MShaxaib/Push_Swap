
#include "ft_stack.h"

int stk_length(t_stack *stk)
{
	t_node *temp;
	int     ctr;

	ctr = 0;

	if(!stk || !stk->head)
		return(0);
	temp = stk->head;
	while(temp)
	{
		ctr++;
		temp = temp->previous;
	}
	return(ctr);
}


void	update_index(t_stack *stk)
{
	int		i;
	t_node	*iter;

	iter = stk -> head;
	i = 0;
	if (iter)
	{
		while (i < stk_length(stk))
		{
			iter->index = i;
			iter =  iter->previous;
			i ++;
		}
	}
}
