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
	while(stack_a->prev)
		stack_a = stack_a->prev;
	while (stack_a)
	{
		ft_printf("a = %d index %d index_tmp %d subs %d", stack_a->num, stack_a->index, stack_a->index_tmp, stack_a->subs);
		stack_a = stack_a->next;
		if (stack_b)
		{
			ft_printf("  b = %d", stack_b->num);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
	if (stack_b)
	{
		while (stack_b)
		{
			ft_printf("            b = %d\n", stack_b->num);
			stack_b = stack_b->next;
		}
	}
}

int	abs_val(int value)
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

void	indexing(t_push *stack_a, int length, int all_numbers)
{
	int		tmp;
	t_push	*first;
	t_push	*tmp_ptr;

	first = stack_a;
	while (length--)
	{
		stack_a = first;
		tmp = -2147483648;
		while (stack_a)
		{
			if (stack_a->num > tmp && stack_a->index == -1)
			{
				tmp = stack_a->num;
				tmp_ptr = stack_a;
			}
			if (stack_a->next == NULL)
				break ;
			stack_a = stack_a->next;
		}
		if (all_numbers == 1)
			tmp_ptr->index = length;
	}
}

void	indexing_partial(t_push *stack_a, int length)
{
	int		tmp;
	t_push	*first;
	t_push	*tmp_ptr;

	first = stack_a;
	while (stack_a)
	{
		stack_a->index_tmp = -1;
		stack_a = stack_a->next;
	}
	while (length--)
	{
		stack_a = first;
		tmp = -2147483648;
		while (stack_a)
		{
			if (stack_a->num > tmp && stack_a->index_tmp == -1)
			{
				tmp = stack_a->num;
				tmp_ptr = stack_a;
			}
			if (stack_a->next == NULL)
				break ;
			stack_a = stack_a->next;
		}
		tmp_ptr->index_tmp = length;
	}
}

t_push	*lowest_index(t_push *stack)
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

