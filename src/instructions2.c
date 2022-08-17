#include "../push_swap.h"

//if stack b, it returns first in stack b, otherwise first in stack a
t_push	*execute_instructions(t_push *stack_a, t_push *stack_b, \
t_count *instructions)
{
	while (instructions->rr > 0)
	{
		write(1, "rr\n", 3);
		stack_a = r(stack_a);
		stack_b = r(stack_b);
		instructions->rr--;
	}
	while (instructions->rr < 0)
	{
		write(1, "rrr\n", 4);
		stack_a = rr(stack_a);
		stack_b = rr(stack_b);
		instructions->rr++;
	}
	stack_a = rotate_a(stack_a, instructions);
	if (stack_b)
		return (pa(stack_a, stack_b));
	return (stack_a);
}

t_push	*rotate_a(t_push *stack_a, t_count *instructions)
{
	while (instructions->ra > 0)
	{
		write(1, "ra\n", 3);
		stack_a = r(stack_a);
		instructions->ra--;
	}
	while (instructions->ra < 0)
	{
		write(1, "rra\n", 4);
		stack_a = rr(stack_a);
		instructions->ra++;
	}
	return (stack_a);
}

t_push	*execute_stack(t_push *stack, t_count *instr_2, int a_or_b)
{
	instr_2->ra = fastest_route(instr_2->stack_a_pos, go_to_first(stack));
	stack = execute_instructions(go_to_first(stack), NULL, instr_2);
	if (a_or_b == 0)
		stack = sa(stack);
	else
		stack = sb(stack);
	return (stack);
}