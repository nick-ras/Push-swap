#include "../libft/libft.h"

// gcc -Wall -Werror -Wextra main.c -L../libft -lft && ./a.out 1 2 3 4 5

t_list	*ft_lstnew_new(char *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		new = NULL;
		return (new);
	}
	new->next = NULL;
	new->num = ft_atoi(content);
	if(new->num == 0 || new->num == -1)
	{
		write(1, "atoi returned error\n", 19);
		exit(1);
	}
	//printf("Atoi: %d\n", new->num);
	return (new);
}

t_list	*ft_lstnew_empty(int zero)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		new = NULL;
		return (new);
	}
	new->next = NULL;
	new->num = zero;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	t_list	*last_a;

	if (!lst)
		return (NULL);
	last_a = lst;
	i = 0;
	while (last_a->next)
	{
		i++;
		last_a = last_a->next;
	}
	return (last_a);
}

t_list *create_linked_list(int argc, char **argv)
{
	int i;
	t_list *ptr_first;
	t_list *stack_a;
	t_list	*ox2;

	if (argc <= 1)
		return (0);
	printf("argc: %d\n", argc);
	i = 1;
	stack_a = ft_lstnew_new(argv[i]);
	stack_a->previous = NULL;
	i++;
	ptr_first = stack_a;
	//printf("ox2: %d and stirng: %s -- now loop->\n", ptr_first->num, argv[1]);
	while (i < argc)
	{
		stack_a->next = ft_lstnew_new(argv[i]);
		ox2 = stack_a;
		stack_a = stack_a->next;
		stack_a->previous = ox2;
		//printf("in loop: index: %d contains: %d\n", i, stack_a->num);
		i++;
	}
	stack_a->next = NULL;
	while(i > 1)
	{
		//printf("in loop: index: %d contains: %d\n", i, stack_a->num);
		stack_a = stack_a->previous;
		i--;
	}
	return(ptr_first);
}

void sa(t_list *ox2)
{
	t_list *ox1;
	t_list *ox0;
	//t_list	temp_ox1;

	while (ox2->next)
		ox2 = ox2->next;
	ox1 = ox2->previous;
	ox0 = ox1->previous;
	ox0->next = ox2;

	ox2->next = ox1;
	ox1->previous = ox2;
	ox2->previous = ox1->previous;
	ox1->next = NULL;
}

void	pa(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_pa;
	t_list	*last_a;
	t_list	*last_b;

	last_a = ft_lstlast(stack_a);
	last_b = ft_lstlast(stack_b);
	temp_pa = last_b->previous;
	temp_pa->next = NULL;
	last_a->next = last_b;
	temp_pa= last_a->next;
	//write(1, "testtesttes\n", 12);
	temp_pa->next = NULL;
}

void	pb(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_pb;
	t_list	*last_a;
	t_list	*last_b;

	last_a = ft_lstlast(stack_a);
	last_b = ft_lstlast(stack_b);
	temp_pb = last_a->previous;
	temp_pb->next = NULL;
	last_b->next = last_a;
	temp_pb= last_b->next;
	temp_pb->next = NULL;
	printf("++pb functino next   ----> %p\n", stack_b->next);
}

void	ra(t_list *stack_a)
{
	t_list	*temp_ra;
	t_list	*last_a;

	while (stack_a->previous)
		stack_a= stack_a->previous;
	last_a = ft_lstlast(stack_a);

	temp_ra = stack_a->next;
	last_a->next = stack_a;
	stack_a->previous = last_a;
	temp_ra->previous = NULL;
	stack_a->next = NULL;
}

void	rb(t_list *stack_b)
{
	t_list	*temp_rb;
	t_list	*last_b;

	while (stack_b->previous)
		stack_b= stack_b->previous;
	last_b = ft_lstlast(stack_b);
	temp_rb = stack_b->next;
	last_b->next = stack_b;
	stack_b->previous = last_b;
	temp_rb->previous = NULL;
	stack_b->next = NULL;
}

void	rra(t_list *stack_a)
{
	t_list	*temp_ra;
	t_list	*last_a;

	while (stack_a->previous)
		stack_a= stack_a->previous;
	last_a = ft_lstlast(stack_a);
	temp_ra = last_a->previous;
	temp_ra->next = NULL;
	stack_a->previous = last_a;
	last_a->next = stack_a;
	last_a->previous = NULL;
}

void	rrb(t_list *stack_b)
{
	t_list	*temp_rb;
	t_list	*last_b;

	while (stack_b->previous)
		stack_b= stack_b->previous;
	last_b = ft_lstlast(stack_b);
	temp_rb = last_b->previous;
	temp_rb->next = NULL;
	stack_b->previous = last_b;
	last_b->next = stack_b;
	last_b->previous = NULL;
}

void	commands(t_list *stack_a, t_list *stack_b, int command)
{
	if (command == 0)
		sa(stack_a);
	if (command == 1)
		sa(stack_b);
	if (command == 2)
	{
		sa(stack_a);
		sa(stack_b);
	}
	if (command == 3)
		pa(stack_a, stack_b);
	if (command == 4)
		pb(stack_a, stack_b);
	if (command == 5)
		ra(stack_a);
	if (command == 6)
		rb(stack_b);
	if (command == 7) 
	{
		ra(stack_a);
		rb(stack_b);
	}
	if (command == 8)
		rra(stack_a);
	if (command == 9)
		rrb(stack_b);
	if (command == 10)
	{
		rra(stack_a);
		rrb(stack_b);
	}
}

int	sort_check(t_list *stack_a)
{
	t_list	*next_nb;

	next_nb = stack_a;
	while (next_nb->previous)
		next_nb= next_nb->previous;
	stack_a = next_nb;
	while (stack_a->next)
	{
		next_nb = stack_a->next;
		if(stack_a->num > next_nb->num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}


int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp_a;
	t_list	*temp_b;
	t_list	*temp_a_nested;
	t_list	*temp_b_nested;
	int	command;
	int	exp = 2;

	if(argc > 1000)
	{
		write(1, "argc too big", 12);
		return(1);
	}
	stack_a = create_linked_list(argc, argv);
	stack_b = ft_lstnew_empty(0);
	stack_b->previous = NULL;
	temp_a = ft_lstlast(stack_a);
	printf("temp_a ----> %d\n", temp_a->num);
	temp_b = stack_b;
	// temp_b = temp_b;
	// temp_a_nested = stack_a;
	// temp_b_nested = stack_b;
	command = 7;
	if (argc <=5)
	{
		write(1, "small\n", 6);
	}
	else
	{
		while (exp < 1073741824 )
		{
			//CHECK IF SORTED
			//push to b
			while(temp_a->previous)
			{
				printf("--------------------------------\n");
				temp_a_nested = temp_a;
				temp_a = temp_a->previous;
				if (temp_a_nested->num%exp == 1)
				{
					printf("temp_a prev----> %d\n", temp_a->num);
					commands(temp_a_nested, temp_b, 4);
					printf("temp_b next---> %p\n", temp_b->next);
					temp_b = temp_b->next;
					printf("temp_b in loop ----> %d\n", temp_b->num);
					printf("temp_b prev---> %p\n", temp_b->previous);
				}
				else
					commands(temp_a, stack_b, 8);
			}
			//push to a
			while(temp_b_nested->previous)
			{
				commands(temp_a_nested, temp_b, 3);
				temp_b_nested = temp_b_nested->previous;
			}
			temp_a = temp_a->previous;
		}
		exp = exp * 2;
	}
	commands(stack_a, stack_b, command);
}
