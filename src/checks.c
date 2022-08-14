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
				exit_statement_and_free(first);
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

int	sort_check(t_push *stack_a, int argc)
{
	t_push	*next_nb;

	if (argc < 2)
		return (0);
	while (stack_a->next)
	{
		next_nb = stack_a->next;
		if (stack_a->num > next_nb->num)
			return (1);
		stack_a = next_nb;
	}
	//print_lists(stack_a, NULL);
	exit (0);
}
