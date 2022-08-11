#include "../push_swap.h"

// pushes leftovers to b, subfunctions(sorting_back) puts back
void	push_out_and_in(t_push *stack_a, t_push *ptr_lis_last, \
int argc)
{
	int		i;
	t_push	*stack_b;

	stack_a = ft_lstlast_new(stack_a);
	stack_b = NULL;
	i = 0;
	while (i < argc - 1)
	{
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

	instructions = malloc(sizeof(t_count));
	while (stack_b)
	{
		printf("sorting one number now\n");
		stack_a = ft_lstlast_new(stack_a);
		stack_b = ft_lstlast_new(stack_b);
		make_instructions(stack_a, stack_b, instructions);
		stack_b = execute_instructions(stack_a, stack_b, instructions);
		print_lists(stack_a, stack_b);
	}
	final_rotations(stack_a, instructions);
}
