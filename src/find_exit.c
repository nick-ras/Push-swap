#include "../push_swap.h"

t_push	*find_last_in_sequence(t_push *stack_a)
{
	int length = 0;
	t_push *longest = NULL;
	while (stack_a)
	{
		if (stack_a->len >= length)
		{
			length = stack_a->len;
			longest = stack_a;
		}
		if (!stack_a->next)
			break;
		stack_a = stack_a->next;
	}
	return (longest);
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
int numbers_in_order(t_push *first)
{
	t_push *next = first;

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

void	exit_statement_and_free(t_push *stack_a)
{
	void	*next = NULL;

	while (stack_a->prev)
		stack_a = stack_a->prev;
	while (stack_a->next)
	{
		next = stack_a->next;
		if (stack_a)
			free(stack_a);
		stack_a = stack_a->next;
	}
	ft_printf("freeing everything%d\n", next);
	exit(1);
}
