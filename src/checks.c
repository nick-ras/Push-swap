#include "../push_swap.h"

void	check_multiples(t_push *first)
{
	t_push*outer;
	t_push	*inner_up;

	outer = first;
	while (outer->next)
	{
		inner_up = outer->next;
		while (inner_up)
		{
			if (inner_up->num == outer->num)
			{
				write(1, "multiples!\n", 11);
				exit_statement_and_free(first);
			}
			inner_up = inner_up->next;
		}
		outer = outer->next;
	}
}

void	check_if_small_or_big(int argc)
{
	if (argc > 1000 || argc < 2)
	{
		write(1, "argc too big or small!\n", 23);
		exit (1);
	}

}

int	sort_check(t_push *stack_a)
{
	t_push *next_nb;

	next_nb = stack_a;
	while (next_nb->prev)
		next_nb = next_nb->prev;
	stack_a = next_nb;
	while (stack_a->next)
	{
		next_nb = stack_a->next;
		if (stack_a->num > next_nb->num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

// check if order is correct
int	numbers_in_order(t_push *first)
{
	t_push	*next = first;

	while (first->next)
	{
		next = first->next;
		ft_printf("checking order%d - %d\n", first->num, next->num);
		if (first->num > next->num)
		{
			return (1);
		}
		first = first->next;
	}
	ft_printf("end check order\n");
	return (0);
}
