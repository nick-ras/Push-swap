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
	while (stack_a)
	{
		ft_printf("a = %d index %d", stack_a->num, \
		stack_a->index);
		stack_a = stack_a->next;
		if (stack_b)
		{
			ft_printf("  b = %d", stack_b->num);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
	while (stack_b)
	{
		ft_printf("            b = %d\n", stack_b->num);
		stack_b = stack_b->next;
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
