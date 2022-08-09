#include "../push_swap.h"

// returns stack_b_prev
t_push	*pa(t_push *stack_a, t_push *stack_b)
{
	t_push	*prev_b;

	stack_a = ft_lstlast_new(stack_a);
	stack_b = ft_lstlast_new(stack_b);
	prev_b = stack_b->prev;
	prev_b->next = NULL;
	stack_a->next = stack_b;
	stack_b->prev = stack_a;
	stack_b->next = NULL;
	return (prev_b);
}

//if no stack b it returns stack b, else prev stack a
t_push	*pb(t_push *stack_a, t_push *stack_b)
{
	t_push	*prev_a;

	stack_a = ft_lstlast_new(stack_a);
	if (!stack_b)
	{
		prev_a = stack_a->prev;
		prev_a->next = NULL;
		stack_a->prev = NULL;
		return (stack_a);
	}
	else
	{
		stack_b = ft_lstlast_new(stack_b);
		prev_a = stack_a->prev;
		prev_a->next = NULL;
		stack_b->next = stack_a;
		stack_a->prev = stack_b;
		return (prev_a);
	}
}
