#include "../push_swap.h"

int	length_list(t_push *lst)
{
	int		i;

	if (!lst)
		return (0);
	lst = ft_lstlast_new(lst);
	i = 1;
	while (lst->prev)
	{
		i++;
		lst = lst->prev;
	}
	return (i);
}

void	print_lists(t_push *stack_a, t_push *stack_b)
{
	stack_a = ft_lstlast_new(stack_a);
	stack_b = ft_lstlast_new(stack_b);
	while (stack_a)
	{
		ft_printf("a checking from last =   %d index %d\n", stack_a->num, stack_a->index);
		stack_a = stack_a->prev;
	}
	while (stack_b)
	{
		ft_printf("b checking from last =   %d\n", stack_b->num);
		stack_b = stack_b->prev;
	}
}

int	absolute_value(int value)
{
	if (value < 0)
		return (-value);
	else
		return (value);
}

void	exit_statement_and_free(t_push *stack_a)
{
	t_push	*del;

	stack_a = ft_lstlast_new(stack_a);
	while (stack_a)
	{
		del = stack_a;
		stack_a = stack_a->prev;
		free(del);
		del = NULL;
	}
	write(1, "Error\n", 6);
	exit(1);
}
