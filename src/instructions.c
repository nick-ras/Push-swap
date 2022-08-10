#include "../push_swap.h"

void	make_instructions(t_push *stack_a, t_push *stack_b, \
t_count *instructions)
{
	t_push	*tmp_a = stack_a;
	initialize_instructions_struct(instructions);
	while (stack_b)
	{
		ft_printf("checking route from stack b = %d\n", stack_b->num);
		stack_a = ft_lstlast_new(tmp_a); //always start at last
		instructions->stack_a_pos = 0;
		while (stack_a) //from last
		{
			if (make_instructions_subfunction(stack_a, stack_b, instructions))
				set_commands(stack_a, stack_b,instructions);
			stack_a = stack_a->prev;
			instructions->stack_a_pos++;
		}
		stack_b = stack_b->prev;
		instructions->stack_b_pos++;
	}
}

//you could throw it into two dif function depending if its plus or minus
int	make_instructions_subfunction(t_push *stack_a, t_push *stack_b, \
t_count *instructions)
{
	int	b_minussign_a;

	b_minussign_a = stack_b->num - stack_a->num;
	if (b_minussign_a < 1)
		return (0);
	if (b_minussign_a < instructions->lw && \
	absolute_value(fastest_route(instructions->stack_a_pos - instructions->stack_b_pos, stack_a) < absolute_value(instructions->lw_ra))) //hpdnter plus og minus
		return (1);
	return (0);
}

void	set_commands(t_push *stack_a, t_push *stack_b, t_count *instructions)
{
		instructions->rr = instructions->stack_b_pos;
		instructions->lw = stack_b->num - stack_a->num;
		instructions->lw_ra = fastest_route(instructions->stack_a_pos \
		- instructions->stack_b_pos, stack_a);
}

int	fastest_route(int rotations, t_push *stack_a)
{
	int	length;

	length = length_list(stack_a);
	if (rotations > length / 2 && rotations > 0)
		rotations = -length + rotations;
	if (rotations > length / 2 && rotations < 0)
		rotations = length + rotations;
	return (rotations);
}

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

void	final_initialize_instructions_struct(t_count *instructions)
{
	instructions->bg = 0;
	instructions->lw = 0;
	instructions->bg_ra = 0;
	instructions->lw_ra = 0;
	instructions->b = 0;
	instructions->rr = 0;
	instructions->stack_b_pos = 0;
	instructions->stack_a_pos = 0;
}
