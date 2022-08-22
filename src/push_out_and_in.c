#include "../push_swap.h"

t_push	*use_sa(t_push *stack, t_count *instr_2, int argc)
{
	t_push	*next_one;
	int		i;

	i = 0;
	while (i < (length_list(stack) / 2))
	{
		sort_check(go_to_first(stack), instr_2, argc);
		while (stack->next)
		{
			stack = sa_first_and_last(go_to_first(stack), instr_2);
			next_one = stack->next;
			if ((stack->index == next_one->index + 1 && abs_val(fastest_route(instr_2->stack_a_pos, stack) < 3 + length_list(stack) / 5)))
				execute_stack_a(stack, instr_2);
			instr_2->stack_a_pos++;
			sort_check(go_to_first(stack), instr_2, argc);
			stack = stack->next;
		}
		instr_2->stack_a_pos = 0;
		i++;
	}
	return (go_to_first(stack));
}

t_push	*use_sa_5(t_push *stack, t_count *instr_2)
{
	t_push	*next_one;
	int		i;
	int		length;

	length = length_list(stack);
	i = 0;
	indexing_partial(stack, length);
	while (i < (length_list(stack) / 2))
	{
		if (sort_check_partial(go_to_first(stack)))
			break ;
		while (stack->next)
		{
			stack = sa_first_and_last(go_to_first(stack), instr_2);
			next_one = stack->next;
			if ((stack->index_tmp == next_one->index_tmp + 1 && abs_val(fastest_route(instr_2->stack_a_pos, stack) < 3 + length_list(stack) / 5)))
			{
				execute_stack_a(stack, instr_2);
				break ;
			}
			instr_2->stack_a_pos++;
			stack = stack->next;
		}
		instr_2->stack_a_pos = 0;
		i++;
	}
	return (go_to_first(stack));
}

t_push	*sa_first_and_last(t_push *stack, t_count *instr_2)
{
	if (stack->index + 1 == ft_lstlast_new(stack)->index)
	{
		instr_2->ra = -1;
		stack = execute_instructions(stack, NULL, instr_2);
		stack = sa(stack);
	}
	initialize_same_stack(instr_2);
	return (stack);
}

// pushes leftovers to b, subfunctions(sorting_back) puts back
void	push_out_and_in(t_push *stack_a, int argc, t_count *instr_2)
{
	int		i;
	t_push	*stack_b;
	t_push	*tmp;

	stack_b = NULL;
	i = 0;
	//print_lists(stack_a, stack_b);
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
				stack_a = tmp;
			}
		}
		//print_lists(stack_a, stack_b);
		i++;
	}
	sorting_back(go_to_first(stack_a), stack_b, instr_2);
}

//sorting leftover numbers (stack b) back into stack a
void	sorting_back(t_push *stack_a, t_push *stack_b, t_count *instr_2)
{
	initialize_instructions_struct(instr_2);
	while (stack_b)
	{
	  //print_lists(stack_a, stack_b);
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
		stack_a = go_to_first(stack_a);
	}
	sort_low_to_high(stack_a, instr_2);
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
	//print_lists(first, NULL);
	exit_statement_and_free(stack, 0);
}
