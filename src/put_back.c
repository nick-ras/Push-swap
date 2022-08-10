#include "../push_swap.h"

int	length_list(t_push *lst)
{
	int		i;

	if (!lst)
		return (0);
	lst = ft_lstlast_new(lst);
	i = 1;
	while (lst->prev)
	{
		i++;
		lst = lst->prev;
	}
	return (i);
}

t_push	*execute_instructions(t_push *stack_a,t_push *stack_b, t_count *instructions)
{
	t_push		*prev_b;

	stack_a = ft_lstlast_new(stack_a);
	stack_b = ft_lstlast_new(stack_b);
	while (instructions->rr > 0)
	{
		stack_a = r(stack_a);
		stack_b = r(stack_b);
		instructions->rr--;

	}
	while (instructions->rr < 0)
	{
		stack_a = rr(stack_a);
		stack_b = rr(stack_b);
		instructions->rr++;

	}
	while (instructions->lw_ra > 0)
	{
		stack_a = r(stack_a);
		instructions->lw_ra--;
	}
	while (instructions->lw_ra < 0)
	{
		stack_a = rr(stack_a);
		instructions->lw_ra++;
	}
	stack_b = ft_lstlast_new(stack_b);
	prev_b = stack_b->prev;
	stack_b = pa(stack_a, stack_b);
	return (prev_b);
}
