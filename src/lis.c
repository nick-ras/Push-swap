#include "../push_swap.h"

void	make_lis(t_push *stack_a)
{
	t_push	*outer;
	t_push	*first;

	first = stack_a;
	outer = stack_a;
	while (outer)
	{
		stack_a = first;
		while (stack_a && stack_a != outer)
		{
			if (stack_a->next)
			{
				if (stack_a->num < outer->num)
				{
					if (stack_a->len + 1 >= outer->len)
					{
						outer->len = stack_a->len + 1;
						outer->subs = stack_a;
						if (!stack_a->subs)
							stack_a->subs = stack_a;
					}
				}
			}
			stack_a = stack_a->next;
		}
		outer = outer->next;
	}
	clean_lis(first);
}

void	clean_lis(t_push *stack_a)
{
	t_push	*tmp;
	int		count;

	count = 0;
	while (stack_a)
	{
		if (stack_a->len >= count)
		{
			count = stack_a->len;
			tmp = stack_a;
		}
		stack_a = stack_a->next;
	}
	stack_a = tmp->prev;
	tmp = tmp->subs;
	while (stack_a)
	{
		if (stack_a == tmp)
			tmp = tmp->subs;
		else
			stack_a->subs = NULL;
		stack_a = stack_a->prev;
	}
}

t_push	*check_2_at_top(t_push *stack)
{
	t_push	*current;
	t_push	*next_one;
	t_count	*same_stack;
	int		i;

	i = 0;
	same_stack = malloc(sizeof(t_count));
	while (i < 10)
	{
		initialize_same_stack(same_stack);
		current = stack;
		while (stack->next)
		{
			next_one = current->next;
			if ((current->index == next_one->index + 1 \
			&& fastest_route(same_stack->ra, stack) > -4) \
			|| (fastest_route(same_stack->ra, stack) < 4 \
			&& current->index == next_one->index + 1))
			{
				execute_instructions(stack, NULL, same_stack);
				current = sa(current);
				while (current->prev)
					current = current->prev;
				same_stack->ra = 0;
			}
			current = current->next;
		}
		same_stack->ra++;
		i++;
	}
	return (stack);
}

