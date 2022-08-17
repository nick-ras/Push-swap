#include "../push_swap.h"

t_push	*find_lowest_index(t_push *stack)
{
	int		i;
	t_push	*lowest;

	i = 2147483647;

	while (stack)
	{
		if (stack->index <= i)
			lowest = stack;
		stack = stack->next;
	}
	return (lowest);
}

int	highest_index(t_push *stack)
{
	int		tmp;

	tmp = -2147483648;
	while (stack)
	{
		if (stack->num >= tmp)
			tmp = stack->num;
		stack = stack->next;
	}
	return (tmp);
}

t_push	*go_to_first(t_push *stack)
{
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

int	fastest_route(int rotations, t_push *stack_a)
{
	int	length;

	length = length_list(stack_a);
	if (rotations > length / 2 && rotations > 0)
		rotations = -length + rotations;
	if (rotations > length / 2 && rotations < 0)
		rotations = length + rotations;
	return (rotations);
}
