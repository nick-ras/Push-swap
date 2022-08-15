
#include "../push_swap.h"

void	initialize_instructions_struct(t_count *instructions)
{
	instructions->dif = -2147483648;
	instructions->dif_bg = 2147483647;
	instructions->ra = 1000;
	instructions->rr = 1000;
	instructions->ra_bg = 1000;
	instructions->rr_bg = 1000;
	instructions->stack_b_pos = 0;
	instructions->stack_a_pos = 0;
}

void	initialize_same_stack(t_count *instructions)
{
	instructions->stack_a_pos = 0;
	instructions->ra = 0;
}

void	final_initialize_instructions_struct(t_count *instructions)
{
	instructions->dif = 2147483647;
	instructions->ra = 0;
	instructions->rr = 0;
	instructions->stack_b_pos = 0;
	instructions->stack_a_pos = 0;
	instructions->lowest = -2147483648;
}