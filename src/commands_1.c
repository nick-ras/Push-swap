#include "../push_swap.h"

t_push *commands(t_push *stack_a, t_push *stack_b, int command)
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

// 0
void sa(t_push *ox2)
{
	t_push *ox1;
	t_push *ox0;
	// t_push	temp_ox1;

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
void pa(t_push *stack_a, t_push *stack_b)
{
	t_push *prev_b;

	stack_a = ft_lstlast(stack_a);
	stack_b = ft_lstlast(stack_b);
	prev_b = stack_b->prev;
	prev_b->next = NULL;
	stack_a->next = stack_b;
	stack_b->prev = stack_a;
	stack_b->next = NULL;
}
//           4
t_push	*pb(t_push *stack_a, t_push *stack_b)
{
	t_push *prev_a_pb;
	t_push*last_b;
	
	// If no stack b
	if (!stack_b)
	{
		prev_a_pb = stack_a->prev;
		prev_a_pb->next = NULL;
		stack_b = stack_a;
		stack_b->prev = NULL;
		return (stack_a);
	}
	//if stack_b
	else
	{
		prev_a_pb = stack_a->prev;
		prev_a_pb->next = NULL;
		last_b = ft_lstlast(stack_b);
		last_b->next = stack_a;
		stack_a->prev = last_b;
		return (stack_a);
	}
}
