#include "../push_swap.h"

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
			printf("rotate = %d \n", last_main->num);
		}
		// pushed to b
		else
		{
			if(last_main->prev)
				last_main = last_main->prev;
			stack_b = pb(temp_main, stack_b);
			printf("pushed b = %d \n", last_main->num);
		}
		i++;
	}
	// just testing
	t_push *temp_a = ft_lstlast_new(stack_a);
	t_push *temp_b = ft_lstlast_new(stack_b);
	
	while (temp_a)
	{
		printf("a checking = %d\n", temp_a->num);
		temp_a = temp_a->prev;
	}
	while (temp_b)
	{
		printf("b checking = %d\n", temp_b->num);
		temp_b = temp_b->prev;
	}
	ft_printf("stack b testing    %d\n\n", stack_b->num);
	calculating_and_sorting_back_to_a(last_main, stack_b, argc);
	return (last_main);
}