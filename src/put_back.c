#include "../push_swap.h"

t_push	*execute_instructions(t_push *last_main,t_push *stack_b, t_count *instructions)
{
	t_push		*prev_b;

	while (instructions->rr > 0)
	{
		r(last_main);
		r(stack_b);
		instructions->rr--;

	}
	while (instructions->rr < 0)
	{
		rr(last_main);
		rr(stack_b);
		instructions->rr++;

	}
	while (instructions->lw_ra > 0)
	{
		r(last_main);
		instructions->lw_ra--;
	}
	while (instructions->lw_ra < 0)
	{
		rr(last_main);
		instructions->lw_ra++;
	}
	stack_b = ft_lstlast_new(stack_b);
	prev_b = stack_b->prev;
	stack_b = pa(last_main, stack_b);
	return (prev_b);
}
