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
	t_count	*instructions_2;

	instructions_2 = malloc(sizeof(t_count));
	// if (stack_b)
	// 	print_lists(stack_a, stack_b);
	// else
	// 	print_lists(stack_a, NULL);
	while (stack_b)
	{
		make_instructions(stack_a, stack_b, instructions_2);
		if (absolute_value(instructions_2->ra_bg) + absolute_value(instructions_2->rr_bg) \
		< absolute_value(instructions_2->ra) + absolute_value(instructions_2->rr))
			stack_b = execute_instructions_bg(stack_a, stack_b, instructions_2);
		else
			stack_b = execute_instructions(stack_a, stack_b, instructions_2);
		while (stack_a->prev)
			stack_a = stack_a->prev;
		if (stack_b)
			print_lists(stack_a, stack_b);
		else
			print_lists(stack_a, NULL);
	}
	free(stack_a);
	free(instructions_2);
	stack_a = NULL;
	instructions_2 = NULL;
}

t_push	*check_2_at_top(t_push *stack)
{
	t_push	*current;
	t_push	*next_one;
	t_count	*instructions_2;
	int		i;

	i = 0;
	instructions_2 = malloc(sizeof(t_count));
	while (i < 10) // maybe i < 4 / length_list(stack_a)
	{
		initialize_same_stack(instructions_2);
		current = stack;
		while (current->next)
		{
			next_one = current->next;
			if ((current->index == next_one->index + 1 \
			&& fastest_route(instructions_2->stack_a_pos, stack) > -4) \
			|| (fastest_route(instructions_2->stack_a_pos, stack) < 4 \
			&& current->index == next_one->index + 1))
			{
				instructions_2->ra = fastest_route(instructions_2->stack_a_pos, stack);
				stack = execute_instructions(stack, NULL, instructions_2);
				current = sa(current);
				stack = current;
			}
			//print_lists(stack, NULL);
			instructions_2->stack_a_pos++;
			sort_check(current, instructions_2);
			current = current->next;
		}
		instructions_2->stack_a_pos = 0;
		i++;
	}
	free(instructions_2);
	instructions_2 = NULL;
	return (stack);
}
