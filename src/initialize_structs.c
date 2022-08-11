
#include "../push_swap.h"

void	initialize_instructions_struct(t_count *instructions)
{
	instructions->dif = 1000;
	instructions->ra = 1000;
	instructions->rr = 1000;
	instructions->lowest = 0;
	instructions->stack_b_pos = 0;
	instructions->stack_a_pos = 0;
}

void	final_initialize_instructions_struct(t_count *instructions)
{
	instructions->dif = 0;
	instructions->ra = 0;
	instructions->rr = 0;
	instructions->lowest = 0;
	instructions->stack_b_pos = 0;
	instructions->stack_a_pos = 0;
}