#include "libft_for_push_swap/libft.h"

// clear && gcc -g main.c -Llibft_for_push_swap -lft && ./a.out 1 2 3 4 5 1

t_list *ft_lstnew_new(char *content, t_list *stack_a)
{
	t_list *new;

	new = malloc(sizeof(t_list));
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

t_list *ft_lstnew_empty(int zero)
{
	t_list *new;

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

t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list *create_linked_list(int argc, char **argv)
{
	int i;
	t_list *ptr_first;
	t_list *stack_a;
	t_list *ox2;

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

// 0
void sa(t_list *ox2)
{
	t_list *ox1;
	t_list *ox0;
	// t_list	temp_ox1;

	while (ox2->next)
		ox2 = ox2->next;
	if (ox2->prev)
		ox1 = ox2->prev;
	if (ox1->prev)
		ox0 = ox1->prev;
	ox0->next = ox2;
	ox2->next = ox1;
	ox1->prev = ox2;
	ox2->prev = ox1->prev;
	ox1->next = NULL;
}
// 3
void pa(t_list *stack_a, t_list *stack_b)
{
	t_list *prev_b;

	stack_a = ft_lstlast(stack_a);
	stack_b = ft_lstlast(stack_b);
	prev_b = stack_b->prev;
	prev_b->next = NULL;
	stack_a->next = stack_b;
	stack_b->prev = stack_a;
	stack_b->next = NULL;
}
//           4
t_list	*pb(t_list *stack_a, t_list *stack_b)
{
	t_list *prev_a_pb;
	t_list*last_b;
	
	// If no stack b
	if (!stack_b)
	{
		
		prev_a_pb = stack_a->prev;
		prev_a_pb->next = NULL;
		stack_b = stack_a;
		stack_b->prev = NULL;
	}
	//if stack_b
	else
	{
		prev_a_pb = stack_a->prev;
		last_b = ft_lstlast(stack_b);
		last_b->next = stack_a;
		stack_a->prev = last_b;
		prev_a_pb->next = NULL;
	}
	return (stack_b);
}

void ra(t_list *stack_a)
{
	t_list *prev_a_rra;
	t_list *last_a;

	while (stack_a->prev)
		stack_a = stack_a->prev;
	last_a = ft_lstlast(stack_a);

	prev_a_rra = stack_a->next;
	last_a->next = stack_a;
	stack_a->prev = last_a;
	prev_a_rra->prev = NULL;
	stack_a->next = NULL;
}

void rb(t_list *stack_b)
{
	t_list *temp_rb;
	t_list *last_b;

	while (stack_b->prev)
		stack_b = stack_b->prev;
	last_b = ft_lstlast(stack_b);
	if (stack_b->next)
		temp_rb = stack_b->next;
	last_b->next = stack_b;
	stack_b->prev = last_b;
	temp_rb->prev = NULL;
	stack_b->next = NULL;
}

t_list	*rra(t_list *stack_a)
{
	t_list *prev_a_rra;
	t_list *last_a;

	while (stack_a->prev)
		stack_a = stack_a->prev;
	last_a = ft_lstlast(stack_a);
	prev_a_rra = last_a->prev;
	prev_a_rra->next = NULL;
	stack_a->prev = last_a;
	last_a->next = stack_a;
	last_a->prev = NULL;
	return (prev_a_rra);
}

void rrb(t_list *stack_b)
{
	t_list *temp_rb;
	t_list *last_b;

	while (stack_b->prev)
		stack_b = stack_b->prev;
	last_b = ft_lstlast(stack_b);
	temp_rb = last_b->prev;
	temp_rb->next = NULL;
	stack_b->prev = last_b;
	last_b->next = stack_b;
	last_b->prev = NULL;
}

t_list *commands(t_list *stack_a, t_list *stack_b, int command)
{
	// if (command == 0)
	// 	sa(stack_a);
	// else if (command == 1)
	// 	sa(stack_b);
	// else if (command == 2)
	// {
	// 	sa(stack_a);
	// 	sa(stack_b);
	// }
	// else if (command == 3)
	// 	pa(stack_a, stack_b);
	if (command == 4)
		return (pb(stack_a, stack_b));
	// else if (command == 5)
	// 	ra(stack_a);
	// else if (command == 6)
	// 	rb(stack_b);
	// else if (command == 7)
	// {
	// 	ra(stack_a);
	// 	rb(stack_b);
	// }
	if (command == 8)
		return (rra(stack_a));
	// else if (command == 9)
	// 	rrb(stack_b);
	// else if (command == 10)
	// {
	// 	rra(stack_a);
	// 	rrb(stack_b);
	// }
}

t_list *find_last_in_sequence(t_list *stack_a)
{
	int length = 0;
	t_list *longest = NULL;
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

int sort_check(t_list *stack_a)
{
	t_list *next_nb;

	next_nb = stack_a;
	while (next_nb->prev)
		next_nb = next_nb->prev;
	stack_a = next_nb;
	while (stack_a->next)
	{
		next_nb = stack_a->next;
		if (stack_a->num > next_nb->num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

// check if order is correct
int numbers_in_order(t_list *first)
{
	t_list *next = first;

	while (first->next)
	{
		next = first->next;
		printf("checking order%d - %d\n", first->num, next->num);
		if (first->num > next->num)
		{
			return (1);
		}
		first = first->next;
	}
	printf("end check order\n");
}

void empty_stack_b(t_list *stack_a, t_list *stack_b)
{
	t_list *temp;
	stack_b = ft_lstlast(stack_b);
	/* 	while(stack_b->prev)
		{
			stack_b = stack_b->prev;
			printf("  emptying stack   all b%d\n", stack_b->num);
		} */
	while (stack_b->num)
	{
		temp = stack_b->prev;
		commands(stack_a, stack_b, 3); // pushes b to stack a
		stack_b = temp;
		printf("last b %d\n", stack_b->num);
	}
}

void check_multiples(t_list *first)
{
	t_list *outer;
	t_list *inner_up;

	outer = first;
	while (outer->next)
	{
		inner_up = outer->next;
		while (inner_up)
		{
			if (inner_up->num == outer->num)
			{
				write(1, "multiples!\n", 11);
				exit(1);
			}
			inner_up = inner_up->next;
		}
		outer = outer->next;
	}
}

void	check_if_small_or_big(int argc)
{
	if (argc > 1000 || argc < 2)
	{
		write(1, "argc too big or small!\n", 23);
		exit (1);
	}

}

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	t_list *longest = NULL;
	printf("argc: %d\n", argc);
	check_if_small_or_big(argc);
	stack_a = create_linked_list(argc, argv);
	stack_b = NULL;
	check_multiples(stack_a);

	t_list *outer = stack_a;
	t_list *inner = stack_a;
	t_list *temp = stack_a;

	if (argc <= 5)
		write(1, "small\n", 6);
	int twotimes = 0;
		
	// makes LIS-----------------------
	outer = stack_a;
	printf("Beginning main loop\n");
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

	// finds last number in LIS
	longest = find_last_in_sequence(stack_a);

	// DEBUGGING showing whole sequence that need to be pushed to stack_b
	t_list *longest_debugging= longest;
	while (longest_debugging)
	{
		printf("LIS number %d\n", longest_debugging->num);
		longest_debugging = longest_debugging->subs;
	}
	
	// rotates and pushed numbers
	t_list *last_main = ft_lstlast(stack_a);
	t_list	*temp_main;
	int	i = 0;

	while (i < argc - 1)
	{
		temp = last_main;
		// rotated a
		if (temp->num == longest->num)
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
			stack_b = pb(temp, stack_b);
			printf("pushed b = %d \n", last_main->num);
		}
		i++;
	}

	/* int	twosortings = 0;
	if (twosortings < 1)
	{
		twosortings == 0;
		continue;
	}
	twosortings++; */

	// Now put all from stack b to stack a
	//empty_stack_b(stack_a, stack_b);

	// just testing
	t_list *temp_a = stack_a;
	t_list *temp_b = stack_b;
	while (temp_a)
	{
		printf("a checking = %d\n", temp_a->num);
		temp_a = temp_a->next;
	}
	while (temp_b)
	{
		printf("b checking = %d\n", temp_b->num);
		temp_b = temp_b->next;
	}
	
	printf("\nlist sorted!\n");
}
