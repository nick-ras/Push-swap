#include "../push_swap.h"

t_push *ft_lstnew_new(char *content, t_push *stack_a)
{
	t_push *new;

	new = malloc(sizeof(t_push));
	if (!new)
	{
		new = NULL;
		return (new);
	}
	new->next = NULL;
	new->num = ft_atoi(content, stack_a);
	new->len = 1;
	new->subs = NULL;
	return (new);
}

int	ft_lstsize_new(t_push *lst)
{
	int		i;
	t_push	*temp;

	if (!lst)
		return (0);
	temp = lst;
	i = 1;
	while (temp->next)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
t_push *create_linked_list(int argc, char **argv)
{
	int i;
	t_push *ptr_first;
	t_push *stack_a;
	t_push *ox2;

	i = 1;
	stack_a = ft_lstnew_new(argv[i], stack_a);
	i++;
	ptr_first = stack_a;
	stack_a->prev = NULL;
	while (i < argc)
	{
		stack_a->next = ft_lstnew_new(argv[i], stack_a);
		ox2 = stack_a;
		stack_a = stack_a->next;
		stack_a->prev = ox2;
		i++;
	}
	stack_a->next = NULL;
	return (ptr_first);
}