
#include "ft_stack.h"

int stk_length(t_stack *stk)
{
	t_node *temp;
	int		ctr;

	ctr = 0;
	if(!stk || !stk->head)
		return(0);
	temp = stk->head;
	while(temp != NULL)
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

	i = 0;
	if (!stk || !stk->head)
		return ;
	iter = stk->head;
	while (iter)
	{
			iter->index = i;
			i++;
			iter = iter->previous;
	}
	
}
