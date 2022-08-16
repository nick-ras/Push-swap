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
		print_lists(stack_a, stack_b);
		if (sort_check_while_pb(stack_a))
			break ;
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
	t_count	*instr_2;

	instr_2 = malloc(sizeof(t_count));
	// if (stack_b)
	// 	print_lists(stack_a, stack_b);
	// else
	// 	print_lists(stack_a, NULL);
	while (stack_b)
	{
		make_instructions(stack_a, stack_b, instr_2);
		if (absolute_value(instr_2->ra_bg) + absolute_value(instr_2->rr_bg) \
		< absolute_value(instr_2->ra) + absolute_value(instr_2->rr))
			stack_b = execute_instructions_bg(stack_a, stack_b, instr_2);
		else
			stack_b = execute_instructions(stack_a, stack_b, instr_2);
		while (stack_a->prev)
			stack_a = stack_a->prev;
		/* if (stack_b)
			print_lists(stack_a, stack_b);
		else
			print_lists(stack_a, NULL); */
	}
	free(stack_a);
	free(instr_2);
	stack_a = NULL;
	instr_2 = NULL;
}

t_push	*check_2_at_top(t_push *stack)
{
	t_push	*next_one;
	t_count	*instr_2;
	int		i;

	i = 0;
	instr_2 = malloc(sizeof(t_count));
	while (i < 10)
	{
		initialize_same_stack(instr_2);
		stack = check_first_and_last(go_to_first(stack), instr_2);
		while (stack->next)
		{
			next_one = stack->next;
			if ((stack->index == next_one->index + 1 \
			&& absolute_value(fastest_route(instr_2->stack_a_pos, stack) > 4) && stack->index == next_one->index + 1))
			{
				instr_2->ra = fastest_route(instr_2->stack_a_pos, go_to_first(stack));
				stack = execute_instructions(go_to_first(stack), NULL, instr_2);
				stack = sa(stack);
			}
			instr_2->stack_a_pos++;
			print_lists(go_to_first(stack), NULL);
			sort_check(go_to_first(stack), instr_2);
			stack = stack->next;
		}
		instr_2->stack_a_pos = 0;
		i++;
	}
	free(instr_2);
	instr_2 = NULL;
	return (go_to_first(stack));
}

t_push	*check_first_and_last(t_push *stack, t_count *instr_2)
{
	while (stack->index == ft_lstlast_new(stack)->index - 1)
	{
		instr_2->ra = -1;
		stack = execute_instructions(stack, NULL, instr_2);
		stack = sa(stack);
	}
	return (stack);
}

void	sort_low_to_high(t_push *stack, t_count	*instr_2)
{
	t_push	*first;

	first = stack;
	instr_2->ra = 0;
	while (stack)
	{
		if (stack->index == 0)
			break ;
		stack = stack->next;
		instr_2->ra++;
	}
	instr_2->ra = fastest_route(instr_2->ra, stack);
	first = execute_instructions(first, NULL, instr_2);
	//print_lists(first, NULL);
	exit_statement_and_free(stack, 0);
}
