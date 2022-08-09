#include "../push_swap.h"

void	initialize_instructions_struct(t_count *instructions)
{
	instructions->bg = 1000;
	instructions->lw = 1000;
	instructions->bg_ra = 1000;
	instructions->lw_ra = 1000;
	instructions->b = 1000;
	instructions->rr = 1000;
	instructions->stack_b_pos = 0;
	instructions->stack_a_pos = 0;
}

void	make_instructions(t_push *stack_a, t_push *stack_b, \
t_count *instructions)
{
	initialize_instructions_struct(instructions);
	while (stack_b)
	{
		ft_printf("start outer\n");
		stack_a = ft_lstlast_new(stack_a); //always start at last
		instructions->stack_a_pos = instructions->stack_b_pos;
		while (stack_a->prev) //from last
		{
			if (check_and_update_instructions(stack_a, stack_b, instructions))
				set_commands(stack_a, instructions);
			stack_a = stack_a->prev;
			instructions->stack_a_pos++;
		}
		ft_printf("b %d\n", stack_b->num);
		stack_b = stack_b->prev;
		instructions->stack_b_pos++;
	}
}

//you could throw it into two dif function depending if its plus or minus
int	check_and_update_instructions(t_push *stack_a, t_push *stack_b, \
t_count *instructions)
{
	int	b_minus_a;

	b_minus_a = stack_b->num - stack_a->num;
	if (b_minus_a < 1)
		return (0);
	if (b_minus_a < instructions->lw && \
	fastest_route(instructions->stack_a_pos - instructions->stack_b_pos, \
	stack_a) < instructions->lw_ra)
	{
		return (1);
	}
	return (0);
}

void	set_commands(t_push *stack_a, t_count *instructions)
{
		instructions->rr = instructions->stack_b_pos;
		instructions->lw_ra = fastest_route(instructions->stack_a_pos \
		- instructions->stack_b_pos, stack_a);
}

int	fastest_route(int rotations, t_push *stack_a)
{
	int	length;

	length = length_list(stack_a);
	if (rotations > length / 2)
		rotations = -length + rotations;
	return (rotations);
}
