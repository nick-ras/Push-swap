#include "../push_swap.h"

void	make_lis(t_push *stack_a)
{
	t_push *outer = stack_a;
	t_push *inner = stack_a;
	outer = stack_a;
	while (outer)
	{
		inner = stack_a;
		while (inner && inner != outer)
		{
			if (inner->num < outer->num)
			{
				if (inner->len + 1 >= outer->len)
				{
					outer->len = inner->len + 1;
					outer->subs = inner;
				}
			}
			inner = inner->next;
		}
		outer = outer->next;
	}
}

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

// rotates and pushed numbers
t_push	*lis_pushing_to_b(t_push *stack_a, t_push *stack_b, t_push *longest, int argc)
{
	int		i;

	i = 0;
	stack_a = ft_lstlast_new(stack_a);
	while (i < argc - 1)
	{
		// rotated a
		if (stack_a->num == longest->num)
		{
			if (longest->subs)
				longest = longest->subs;
			stack_a = commands(stack_a, NULL, 8);
			ft_printf("abc rotate = %d \n", stack_a->num);
		}
		// pushed to b
		else
		{
			if (stack_a->prev)
				stack_a = stack_a->prev;
			stack_b = pb(stack_a, stack_b);
			ft_printf("abc pushed b = %d \n", stack_a->num);
		}
		i++;
	}
	print_lists(stack_a, stack_b);
	return (stack_a);
}
