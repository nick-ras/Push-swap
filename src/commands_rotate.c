#include "../push_swap.h"

t_push	*r(t_push *last)
{
	t_push	*sec_last;
	t_push	*first;

	if (length_list(last) < 2)
		return (last);
	last = ft_lstlast_new(last);
	first = last;
	while (first->prev)
		first = first->prev;
	sec_last = last->prev;
	sec_last->next = NULL;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	return (sec_last);
}

//no need to use lstlast
void	rr(t_push *stack_b)
{
	t_push	*new_first;
	t_push	*last_b;
	t_push	*first;

	if (length_list(stack_b) < 2)
		return ;
	last_b = ft_lstlast_new(stack_b);
	first = stack_b;
	while (first->prev)
		first = first->prev;
	if (first->next)
		new_first = first->next;
	last_b->next = first;
	first->prev = last_b;
	new_first->prev = NULL;
	first->next = NULL;
}