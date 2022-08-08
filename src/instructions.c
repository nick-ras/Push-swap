#include "../push_swap.h"

void	print_lists(t_push *stack_a, t_push *stack_b)
{
	while (stack_a)
	{
		ft_printf("a checking from last =   %d\n", stack_a->num);
		stack_a = stack_a->prev;
	}
	while (stack_b)
	{
		ft_printf("b checking from last =   %d\n", stack_b->num);
		stack_b = stack_b->prev;
	}
}

void	make_instructions(t_push *stack_a, t_push *stack_b, \
t_count *instructions)
{
	t_push	*first;

	first = stack_a;
	initialize_instructions_struct(instructions);
	//lav outer loop så der tjekkes for hvert tal nedadgående i b
	//while(stack_b->prev)
	//check rotations to get lower on top of a (by check smallest instructions)
	while (stack_b)
	{
		ft_printf("start outer\n");
		stack_a = first;
		instructions->stack_a_pos = fastest_route \
		(instructions->stack_b_pos, stack_b);
		while (stack_a->prev)
		{
			check_if_route_shorter(stack_a, stack_b, instructions);
			stack_a = stack_a->prev;
			instructions->stack_a_pos++;
		}
		ft_printf("lw_ra %d   lw %d\n", instructions->lw_ra, instructions->lw);
		stack_b = stack_b->prev;
		instructions->stack_b_pos++;
	}							
	return (instructions);
}

void	initialize_instructions_struct(t_count *instructions)
{
	instructions->bg = 1000;
	instructions->lw = 1000;
	instructions->bg_ra = 1000;
	instructions->lw_ra = 1000;
	instructions->b = 1000;
	instructions->rrr = 1000;
	instructions->stack_b_pos = 0;
	instructions->stack_a_pos = 0;
}

void	check_if_route_shorter(t_push *stack_a, t_push *stack_b, \
t_count *instructions)
{
	int	b_minus_a;

	// + = a > b
	//smth with modulus
	b_minus_a = stack_b->num - stack_a->num;
	//you could throw it into two dif function depending if its plus or minus
	if (b_minus_a < 1)
		return ;
	//finding smallet difference + checking rotations needed
	if (b_minus_a < instructions->lw && b_minus_a > 0 && \
	fastest_route(length_list(stack_a) - instructions->stack_b_pos, stack_a) \
		+ instructions->stack_b_pos < instructions->lw_ra)
	{
		instructions->lw = b_minus_a;
		instructions->lw_ra = fastest_route(instructions->stack_a_pos, stack_a);
		instructions->rrr = fastest_route(instructions->stack_b_pos, stack_b);
	}
}

//will determine if the fastest way is to do ra og rra (reverse)
int	fastest_route(int rotations, t_push *stack_a)
{
	int	length;

	length = length_list(stack_a);
	if (rotations > length / 2)
		rotations = -length + rotations;
	return (rotations);
}
