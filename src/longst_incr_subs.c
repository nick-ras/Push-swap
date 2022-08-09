#include "../push_swap.h"

void	make_lis(t_push *stack_a)
{
	t_push	*outer;
	t_push	*inner;

	outer = stack_a;
	inner = stack_a;
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
	int		length;
	t_push	*longest;

	length = 0;
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

// pushed numbers, that are not in the longest increasing subsequence, to stack b. Afterwards it hands stack a and stack b to other functions that handles the instructions to put stack b numbers back to stack a
void	sorting_pipeline(t_push *stack_a, t_push *longest, int argc)
{
	int		i;
	t_push	*stack_b;

	stack_b = NULL;
	i = 0;
	while (i < argc - 1)
	{
		stack_a = ft_lstlast_new(stack_a);
		if(stack_b)
			stack_b = ft_lstlast_new(stack_b);
		if (!stack_a->prev)
			break ;
		if (stack_a->num == longest->num)  // rotated a
		{
			if (longest->subs)
				longest = longest->subs;
			ft_printf("abc ra = %d \n", stack_a->num);
			stack_a = r(stack_a);
		}
		else    // pushed to b
		{
			ft_printf("abc pb = %d \n", stack_a->num);
			if (!stack_b)
			{
				stack_a = stack_a->prev;
				stack_b = pb(stack_a, stack_b);
			}
			else
				stack_a = pb(stack_a, stack_b);
		}
		i++;
	}
	print_lists(stack_a, stack_b);
	sorting_back(stack_a, stack_b);
}

//sorting leftover numbers (stack b) back into stack a
void	sorting_back(t_push *stack_a, t_push *stack_b)
{
	t_count	*instructions;
	int		ii;

	instructions = malloc(sizeof(t_count));
	ii = 0;
	while (ii < 5)
	{
		stack_a = ft_lstlast_new(stack_a);
		stack_b = ft_lstlast_new(stack_b);
		make_instructions(stack_a, stack_b, instructions);
		execute_instructions(stack_a, stack_b, instructions);
		print_lists(stack_a, stack_b);
		ii++;
	}
}
