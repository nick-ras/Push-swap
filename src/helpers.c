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
	ft_printf("list\n");
	while (stack_a)
	{
		ft_printf("a = %d index %d", stack_a->num, stack_a->index);
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

void	exit_statement_and_free(t_push *stack_a, int i)
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
	if (i == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	else
		exit (0);
}

void	sort_low_to_high(t_push *stack, t_count	*instr_2)
{
	t_push	*first;

	first = stack;
	instr_2->ra = 0;
	while (stack)
	{
		if (stack->index == 0)
			break ;
		stack = stack->next;
		instr_2->ra++;
	}
	instr_2->ra = fastest_route(instr_2->ra, stack);
	first = execute_instructions(first, NULL, instr_2);
	//print_lists(first, NULL);
	exit_statement_and_free(stack, 0);
}
