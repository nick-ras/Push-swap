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
	if (argc >= 500 || argc <= 2)
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

void	sort_check(t_push *stack_a, t_count *instructions_2)
{
	t_push	*next_nb;
	t_push	*first;

	first = stack_a;
	while (stack_a->next)
	{
		next_nb = stack_a->next;
		if (stack_a->index + 1 != next_nb->index)
		{
			if (next_nb->index != 0)
				return ;
		}
		stack_a = next_nb;
	}
	sort_low_to_high(first, instructions_2);
	print_lists(stack_a, NULL);
	exit_statement_and_free(stack_a, 0);
}
