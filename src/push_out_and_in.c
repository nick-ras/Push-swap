#include "../push_swap.h"

// pushes leftovers to b, subfunctions(sorting_back) puts back
void	push_out_and_in(t_push *stack_a, int argc)
{
	int		i;
	t_push	*stack_b;
	t_push	*tmp;

	stack_b = NULL;
	i = 0;
	while (i < argc - 1)
	{
		if (stack_a->subs)
		{
			write(1, "ra\n", 3);
			stack_a = r(stack_a);
		}
		else
		{
			tmp = stack_a->next;
			if (!stack_b)
			{
				stack_b = pb_first_push(stack_a, stack_b);
				stack_a = tmp;
			}
			else
			{
				stack_b = pb(stack_a, stack_b);
				stack_a = tmp;
			}
		}
		i++;
	}
	//print_lists(stack_a, stack_b);
	sorting_back(stack_a, stack_b);
}

//sorting leftover numbers (stack b) back into stack a
void	sorting_back(t_push *stack_a, t_push *stack_b)
{
	t_count	*instructions;

	instructions = malloc(sizeof(t_count));
	// if (stack_b)
	// 	print_lists(stack_a, stack_b);
	// else
	// 	print_lists(stack_a, NULL);
	while (stack_b)
	{
		make_instructions(stack_a, stack_b, instructions);
		if (absolute_value(instructions->ra_bg) + absolute_value(instructions->rr_bg) \
		< absolute_value(instructions->ra) + absolute_value(instructions->rr))
			stack_b = execute_instructions_bg(stack_a, stack_b, instructions);
		else
			stack_b = execute_instructions(stack_a, stack_b, instructions);
		while (stack_a->prev)
			stack_a = stack_a->prev;
		if (stack_b)
			print_lists(stack_a, stack_b);
		else
			print_lists(stack_a, NULL);
	}
	free(stack_a);
	free(instructions);
	stack_a = NULL;
	instructions = NULL;
}
