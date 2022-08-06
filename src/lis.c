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

t_push	*lis_pushing_to_b(t_push *stack_a, t_push *stack_b, t_push *longest, int argc)
{
	// rotates and pushed numbers
	t_push *last_main = ft_lstlast_new(stack_a);
	t_push	*temp_main;
	int	i = 0;

	while (i < argc - 1)
	{
		temp_main = last_main;
		// rotated a
		if (temp_main->num == longest->num)
		{
			if(longest->subs)
				longest = longest->subs;
			last_main = commands(last_main, NULL, 8);
			ft_printf("abc rotate = %d \n", last_main->num);
		}
		// pushed to b
		else
		{
			if(last_main->prev)
				last_main = last_main->prev;
			stack_b = pb(temp_main, stack_b);
			ft_printf("abc pushed b = %d \n", last_main->num);
		}
		i++;
	}
	// just testing
	t_push *temp_a = ft_lstlast_new(stack_a);
	t_push *temp_b = ft_lstlast_new(stack_b);
	while (temp_a)
	{
		ft_printf("a checking from last a is =  %d\n", temp_a->num);
		temp_a = temp_a->prev;
	}
	while (temp_b)
	{
		ft_printf("b checking from last b is =  %d\n", temp_b->num);
		temp_b = temp_b->prev;
	}
	calculating_and_sorting_back_to_a(last_main, stack_b);
	return (last_main);
}
