#include "../push_swap.h"

void ra(t_push *stack_a)
{
	t_push *prev_a_rra;
	t_push *last_a;

	while (stack_a->prev)
		stack_a = stack_a->prev;
	last_a = ft_lstlast_new(stack_a);

	prev_a_rra = stack_a->next;
	last_a->next = stack_a;
	stack_a->prev = last_a;
	prev_a_rra->prev = NULL;
	stack_a->next = NULL;
}

void rb(t_push *stack_b)
{
	t_push *temp_rb;
	t_push *last_b;

	while (stack_b->prev)
		stack_b = stack_b->prev;
	last_b = ft_lstlast_new(stack_b);
	if (stack_b->next)
		temp_rb = stack_b->next;
	last_b->next = stack_b;
	stack_b->prev = last_b;
	temp_rb->prev = NULL;
	stack_b->next = NULL;
}

t_push	*rra(t_push *stack_a)
{
	t_push *prev_a_rra;
	t_push *last_a;

	while (stack_a->prev)
		stack_a = stack_a->prev;
	last_a = ft_lstlast_new(stack_a);
	prev_a_rra = last_a->prev;
	prev_a_rra->next = NULL;
	stack_a->prev = last_a;
	last_a->next = stack_a;
	last_a->prev = NULL;
	return (prev_a_rra);
}

void rrb(t_push *stack_b)
{
	t_push *temp_rb;
	t_push *last_b;

	while (stack_b->prev)
		stack_b = stack_b->prev;
	last_b = ft_lstlast_new(stack_b);
	temp_rb = last_b->prev;
	temp_rb->next = NULL;
	stack_b->prev = last_b;
	last_b->next = stack_b;
	last_b->prev = NULL;
}
