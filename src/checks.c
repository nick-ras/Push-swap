#include "../push_swap.h"

void	check_multiples(t_push *first)
{
	t_push	*outer;
	t_push	*inner_up;

	outer = first;
	while (outer->next)
	{
		inner_up = outer->next;
		while (inner_up)
		{
			if (inner_up->num == outer->num)
			{
				exit_statement_and_free(first, 1);
			}
			inner_up = inner_up->next;
		}
		outer = outer->next;
	}
}

void	check_if_small_or_big(int argc)
{
	if (argc > 500 || argc <= 2)
		exit (1);
}

// check if order is correct
int	numbers_in_order(t_push *first)
{
	t_push	*next;

	next = first;
	while (first->next)
	{
		next = first->next;
		if (first->num > next->num)
			return (1);
		first = first->next;
	}
	return (0);
}

void	sort_check(t_push *stack_a, t_count *instructions_2, int argc)
{
	t_push	*next_nb;
	t_push	*first;

	while (stack_a->prev)
		stack_a = stack_a->prev;
	first = stack_a;
	while (stack_a->next)
	{
		next_nb = stack_a->next;
		if (stack_a->num > next_nb->num)
		{
			if (next_nb->index != 0)
				return ;
		}
		stack_a = next_nb;
	}
	if (argc - 1 == length_list(stack_a))
		sort_low_to_high(first, instructions_2);
}

int	sort_check_partial(t_push *stack_a)
{
	t_push	*next_nb;

	while (stack_a->next)
	{
		next_nb = stack_a->next;
		if (stack_a->num > next_nb->num)
			return (0);
		if (stack_a->index_tmp == highest_index(stack_a))
		{
			if (next_nb->index_tmp != 0)
				return (0);
		}
		stack_a = next_nb;
	}
	return (1);
}

int	sort_check_while_pb(t_push *stack_a)
{
	t_push	*next_nb;

	while (stack_a->prev)
		stack_a = stack_a->prev;
	while (stack_a->next)
	{
		next_nb = stack_a->next;
		if (stack_a->index + 1 != next_nb->index)
		{
			if (next_nb != lowest_index(go_to_first(stack_a)))
				return (0);
		}
		stack_a = next_nb;
	}
	return (1);
}
