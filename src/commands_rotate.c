#include "../push_swap.h"

//rotates stack a, and gives new last link
t_push	*r(t_push *last)
{
	t_push	*sec_last;
	t_push	*first;

	if (length_list(last) < 2)
	{
		printf("length list not 2\n"); //change to returning last later
		exit (1);
	}
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

//reverse rotates, returns new last
t_push	*rr(t_push *last)
{
	t_push	*new_first;
	t_push	*first;

	if (length_list(last) < 2)
	{
		printf("length list not 2\n");
		exit (1);
	}
		return (last);
	last = ft_lstlast_new(last);
	first = last;
	while (first->prev)
		first = first->prev;
	new_first = first->next;
	last->next = first;
	first->prev = last;
	new_first->prev = NULL;
	first->next = NULL;
	return (first);
}