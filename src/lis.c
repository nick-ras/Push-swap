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
	t_push	*longest;

	longest = NULL;
	while (stack_a)
	{
		if (stack_a->len >= length)
		{
			length = stack_a->len;
			longest = stack_a;
		}
		if (!stack_a->next)
			break ;
		stack_a = stack_a->next;
	}
	return (longest);
}

// rotates and pushed numbers
void	push_lis_leftover(t_push *stack_a, t_push *longest, int argc)
{
	int		i;
	t_push *temp;
	t_push	*stack_b;

	stack_b = NULL;
	i = 0;
	stack_a = ft_lstlast_new(stack_a);
	while (i < argc - 1)
	{
		if (!stack_a->prev)
			break ;
		// rotated a
		if (stack_a->num == longest->num)
		{
			if (longest->subs)
				longest = longest->subs;
			stack_a = commands(stack_a, NULL, 8);
			ft_printf("abc ra = %d \n", stack_a->num);
		}
		// pushed to b
		else
		{
			temp = stack_a->prev;
			stack_b = pb(stack_a, stack_b);
			stack_a = temp;
		}
		ft_printf("abc pb = %d \n", stack_a->num);
		i++;
	}
	print_lists(stack_a, stack_b);
	t_count *instructions;
	int ii = 0;
	while (ii < 5) //sort_check(stack_a, stack_b)
	{
		instructions = make_instructions( stack_a, stack_b);
		put_back(stack_a, stack_b, instructions);
		print_lists(stack_a, stack_b);
		ii++;
	}
}
