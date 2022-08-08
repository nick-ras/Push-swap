#include "../push_swap.h"

void	print_lists(t_push *stack_a, t_push *stack_b)
{
	t_push *temp_a = ft_lstlast_new(stack_a);
	t_push *temp_b = ft_lstlast_new(stack_b);
	while (temp_a)
	{
	ft_printf("a checking from last =   %d\n", temp_a->num);
	temp_a = temp_a->prev;
	}
	while (temp_b)
	{
		ft_printf("b checking from last =   %d\n", temp_b->num);
		temp_b = temp_b->prev;
	}
}

//will determine if the fastest way is to do ra og rra (reverse)
int	fastest_route(int rotations, t_push *stack_a)
{
	int	length;

	length = length_list(stack_a);
	if (rotations > length / 2)
		rotations = -length + rotations;
	return(rotations);
}

t_count	*make_instructions(t_push *stack_a, t_push *stack_b)
{
	t_count	*instructions = malloc(sizeof(t_count));
	t_push	*first = ft_lstlast_new(stack_a);

	//set again every loop
	instructions->bg = 1000;
	instructions->lw = 1000;
	instructions->bg_pos = 1000;
	instructions->lw_ra = 1000;
	instructions->b = 1000;

	int	b_minus_a = 0;
	int	rotations = 0;
	int	rotations_out = 0;
	
	stack_b = ft_lstlast_new(stack_b);

	//lav outer loop så der tjekkes for hvert tal nedadgående i b
	//while(stack_b->prev)

	//check rotations to get lower on top of a (by check smallest instructions)
	while(stack_b)
	{
		printf("start outer\n");
		stack_a = first;
		rotations = fastest_route(rotations_out, stack_b);
		while (stack_a->prev)
		{
			// + = a > b
			//smth with modulus
			b_minus_a = stack_b->num - stack_a->num;
			//finding smallet difference + checking rotations needed
			if (b_minus_a < instructions->lw && b_minus_a > 0 && fastest_route(length_list(stack_a) - rotations, stack_a) + rotations_out < instructions->lw_ra)
			{
				instructions->lw = b_minus_a;
				instructions->lw_ra = fastest_route(rotations, stack_a);
				instructions->rrr = fastest_route(rotations_out, stack_b);
			}
			stack_a = stack_a->prev;
			rotations++;
		}
		printf("lw_ra %d   lw %d\n", instructions->lw_ra, instructions->lw);
		stack_b = stack_b->prev;
		rotations_out++;
	}							
	return (instructions);
}
