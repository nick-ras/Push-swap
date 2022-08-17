#include "../push_swap.h"

void	make_instructions(t_push *stack_a, t_push *stack_b, \
t_count *instructions)
{
	t_push	*first;

	initialize_instructions_struct(instructions);
	first = stack_a;
	while (stack_b)
	{
		stack_a = first;
		instructions->stack_a_pos = 0;
		while (stack_a)
		{
			make_instructions_subfunction(stack_a, stack_b, instructions);
			stack_a = stack_a->next;
			instructions->stack_a_pos++;
		}
		if (stack_b->next)
			instructions->stack_b_pos++;
		stack_b = stack_b->next;
	}
}

//you could throw it into two dif function depending if its plus or minus
void	make_instructions_subfunction(t_push *stack_a, t_push *stack_b, \
t_count *instructions)
{
	int	a_min_b;

	a_min_b = stack_a->num - stack_b->num;
	if (a_min_b < 0)
	{
		if (a_min_b > instructions->dif)
			set_commands(stack_a, stack_b, instructions);
	}
	else if (a_min_b > 0)
	{
		if (a_min_b < instructions->dif_bg)
			set_commands_bg(stack_a, stack_b, instructions);
	}
}

void	set_commands(t_push *stack_a, t_push *stack_b, t_count *instructions)
{
	instructions->rr = fastest_route(instructions->stack_b_pos, stack_b);
	instructions->ra = fastest_route(instructions->stack_a_pos + 1 \
	- fastest_route(instructions->stack_b_pos, stack_b), stack_a);
	instructions->dif = stack_a->num - stack_b->num;
}

void	set_commands_bg(t_push *stack_a, t_push *stack_b, t_count *instructions)
{
	instructions->ra_bg = fastest_route(instructions->stack_a_pos, stack_a) \
	- fastest_route(instructions->stack_b_pos, stack_b);
	instructions->dif_bg = stack_a->num - stack_b->num;
	instructions->rr_bg = fastest_route(instructions->stack_b_pos, stack_b);
}
