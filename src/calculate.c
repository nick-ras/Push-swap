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

int	half(int rotations, t_push *stack_a)
{
	int	length;

	length = length(stack_a);
	if (rotations > length / 2)
		rotations = -length + rotations;
	return(rotations);
}

count_list	*calculating_and_sorting_back_to_a(t_push *stack_a, t_push *stack_b)
{
	count_list	*recipe = malloc(sizeof(count_list));
	t_push	*first = ft_lstlast_new(stack_a);

	//set again every loop
	recipe->bg = 1000;
	recipe->lw = 1000;
	recipe->bg_pos = 1000;
	recipe->lw_ra = 1000;
	recipe->b = 1000;

	int	b_minus_a = 0;
	int	rotations = 0;
	int	rotations_out = 0;
	
	stack_b = ft_lstlast_new(stack_b);

	//lav outer loop så der tjekkes for hvert tal nedadgående i b
	//while(stack_b->prev)

	//check rotations to get lower on top of a (by check smallest recipe)
	while(stack_b)
	{
		printf("start outer\n");
		stack_a = first;
		rotations = half(rotations_out, stack_b);
		while (stack_a->prev)
		{
			// + = a > b
			//smth with modulus
			b_minus_a = stack_b->num - stack_a->num;
			//finding smallet difference + checking rotations needed
			if (b_minus_a < recipe->lw && b_minus_a > 0 && half(length(stack_a) - rotations) + rotations_out < recipe->lw_ra)
			{
				recipe->lw = b_minus_a;
				recipe->lw_ra = half(rotations, stack_a)
				recipe->rrr = half(rotations_out, stack_b);
			}
			stack_a = stack_a->prev;
			rotations++;
		}
		printf("lw_ra %d   lw %d\n", recipe->lw_ra, recipe->lw);
		stack_b = stack_b->prev;
		rotations_out++;
	}							
	return (recipe);
}

int	rotations_b(int rotations_out, int length)
{
	if (rotations_out >= 0)
		rotations_out++;
	if (rotations_out > length / 2)
		
}
