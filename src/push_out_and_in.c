#include "../push_swap.h"

// pushes leftovers to b, subfunctions(sorting_back) puts back
void	push_out_and_in(t_push *stack_a, int argc, \
t_push *stack_b, t_count *instr_2)
{
	int		i;
	t_push	*tmp;

	i = 0;
	while (i < argc - 1)
	{
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
				stack_b = use_swap(stack_b, instr_2, 1);
				stack_a = tmp;
			}
		}
		i++;
	}
	sorting_back(stack_a, stack_b, instr_2);
}

//sorting leftover numbers (stack b) back into stack a
void	sorting_back(t_push *stack_a, t_push *stack_b, t_count *instr_2)
{
	initialize_instructions_struct(instr_2);
	//print_lists(stack_a, stack_b);
	while (stack_b)
	{
		make_instructions(stack_a, stack_b, instr_2);
		if (abs_val(instr_2->ra_bg) + abs_val(instr_2->rr_bg) \
		< abs_val(instr_2->ra) + abs_val(instr_2->rr))
		{
			instr_2->ra = instr_2->ra_bg;
			instr_2->rr = instr_2->rr_bg;
			stack_b = execute_instructions(stack_a, stack_b, instr_2);
		}
		else
		{
			stack_b = execute_instructions(stack_a, stack_b, instr_2);
		}
		while (stack_a->prev)
			stack_a = stack_a->prev;
		//print_lists(stack_a, stack_b);
	}
	sort_low_to_high(stack_a, instr_2);
}

t_push	*use_swap(t_push *stack, t_count *instr_2, int a_or_b)
{
	t_push	*next_one;
	int		i;

	i = 0;
	while (i < (length_list(stack) / 2))
	{
		if (a_or_b == 0)
			sort_check(go_to_first(stack), instr_2);
		//print_lists(stack, NULL);
		initialize_same_stack(instr_2);
		stack = sa_first_and_last(go_to_first(stack), instr_2);
		while (stack->next)
		{
			//print_lists(stack, NULL);
			next_one = stack->next;
			if ((stack->index == next_one->index + 1 && abs_val(fastest_route(instr_2->stack_a_pos, stack) < 3 + length_list(stack) / 5)))
				execute_stack(stack, instr_2, a_or_b);
			instr_2->stack_a_pos++;
			////print_lists(go_to_first(stack), NULL);
			if (a_or_b == 0)
				sort_check(go_to_first(stack), instr_2);
			stack = stack->next;
		}
		instr_2->stack_a_pos = 0;
		i++;
	}
	//print_lists(stack, NULL);
	return (go_to_first(stack));
}

t_push	*sa_first_and_last(t_push *stack, t_count *instr_2)
{
	while (stack->index == ft_lstlast_new(stack)->index - 1)
	{
		instr_2->ra = -1;
		stack = execute_instructions(stack, NULL, instr_2);
		stack = sa(stack);
	}
	initialize_same_stack(instr_2);
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
	free(instr_2);
	instr_2 = NULL;
	print_lists(first, NULL);
	exit_statement_and_free(stack, 0);
}
