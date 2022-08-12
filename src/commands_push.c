#include "../push_swap.h"

///pushes last b to a, returns stack_b_prev
t_push	*pa(t_push *stack_a, t_push *stack_b)
{
	t_push	*prev_b;

	stack_a = ft_lstlast_new(stack_a);
	if (stack_b->prev)
	{
		prev_b = stack_b->prev;
		prev_b->next = NULL;
	}
	else
		prev_b = NULL;
	stack_a->next = stack_b;
	stack_b->prev = stack_a;
	stack_b->next = NULL;
	write(1, "pa\n", 3);
	return (prev_b);
}

//pushes last a to b (when stack b is NULL), and return stack b
t_push	*pb_first_push(t_push *stack_a, t_push *stack_b)
{
	t_push	*prev_a;

	write(1, "pb\n", 3);
	stack_a = ft_lstlast_new(stack_a);
	if (!stack_a->prev)
		return (stack_b);
	prev_a = stack_a->prev;
	prev_a->next = NULL;
	stack_a->prev = NULL;
	stack_b = stack_a;
	return (stack_b);
}

////pushes last a to b, and returns new last stack a
t_push	*pb(t_push *stack_a, t_push *stack_b)
{
	t_push	*prev_a;

	stack_a = ft_lstlast_new(stack_a);
	write(1, "pb\n", 3);
	if (!stack_a->prev)
		return (stack_a);
	stack_b = ft_lstlast_new(stack_b);
	prev_a = stack_a->prev;
	prev_a->next = NULL;
	stack_b->next = stack_a;
	stack_a->prev = stack_b;
	return (prev_a);
}
