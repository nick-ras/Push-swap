#include "../push_swap.h"

// pushes leftovers to b, subfunctions(sorting_back) puts back
void	push_out_and_in(t_push *stack_a, t_push *ptr_lis_last, int argc)
{
	int		i;
	t_push	*stack_b;
	stack_a = ft_lstlast_new(stack_a);
	stack_b = NULL;
	i = 0;
	while (i < argc - 1)
	{
		if (stack_b) //delete
			stack_b = ft_lstlast_new(stack_b);
		if (stack_a->num == ptr_lis_last->num)
		{
			if (ptr_lis_last->subs)
				ptr_lis_last = ptr_lis_last->subs;
			stack_a = r(stack_a);
		}
		else
		{
			if (!stack_b)
			{
				stack_a = stack_a->prev;
				stack_b = pb_first_push(stack_a, stack_b);
			}
			else
				stack_a = pb(stack_a, stack_b);
		}
		i++;
	}
	print_lists(stack_a, stack_b);
	sorting_back(stack_a, stack_b);
}

//sorting leftover numbers (stack b) back into stack a
void	sorting_back(t_push *stack_a, t_push *stack_b)
{
	t_count	*instructions;
	int		ii;

	instructions = malloc(sizeof(t_count));
	ii = 0;
	while (stack_b)
	{
		printf("sorting one number now\n");
		stack_a = ft_lstlast_new(stack_a);
		stack_b = ft_lstlast_new(stack_b);
		make_instructions(stack_a, stack_b, instructions);
		stack_b = execute_instructions(stack_a, stack_b, instructions);
		print_lists(stack_a, stack_b);
		ii++;
	}
	final_rotations(stack_a, instructions);
	
}

t_push	*execute_instructions(t_push *stack_a,t_push *stack_b, t_count *instructions)
{

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
	if (stack_b)
	{
		stack_b = ft_lstlast_new(stack_b);
		return (pa(stack_a, stack_b));
	}
	return (stack_a);
}
