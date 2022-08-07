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

	length = ft_lstsize_new(stack_a);
	if (rotations > length / 2)
		rotations = -length + rotations;
	return(rotations);
}

count_list	*calculating_and_sorting_back_to_a(t_push *stack_a, t_push *stack_b)
{
	count_list	*dif = malloc(sizeof(count_list));
	t_push	*first = ft_lstlast_new(stack_a);

	//set again every loop
	dif->bg = 1000;
	dif->lw = 1000;
	dif->bg_pos = 1000;
	dif->lw_ra = 1000;
	dif->b = 1000;

	int	nb_dif = 0;
	int	rotations = 0;
	int	rotations_out = 0;
	
	stack_b = ft_lstlast_new(stack_b);

	//lav outer loop så der tjekkes for hvert tal nedadgående i b
	//while(stack_b->prev)

	//check rotations to get lower on top of a (by check smallest dif)
	while(stack_b)
	{
		printf("start outer\n");
		stack_a = first;
		rotations = half(rotations_out, stack_b);
		//smth with modulus
		while (stack_a->prev)
		{
			// + = a > b
			nb_dif = stack_b->num - stack_a->num;
			//iif dif is smaller then stored value and dif is > 0
			if (nb_dif < dif->lw && nb_dif > 0)
			{
			//the iteration becomes dif->dif
				dif->lw = nb_dif;
				rotations = half(rotations, stack_a); 
				dif->lw_ra = rotations;
			}
			stack_a = stack_a->prev;
			rotations++;
		}
		printf("lw_ra %d   lw %d\n", dif->lw_ra, dif->lw);

		stack_b = stack_b->prev;
		rotations_out++;
	}
	
	//check rotations to get bigger on top of a
	// compare how many rb or rrb that needs, and combine with ra or rra into rr or rrr. if lw_ra is plus then its ra and if minus its rra.
	//calculate_num_after(stack_a, stack_b, dif);									
	return (dif);
}

int	rotations_b(int rotations_out, int length)
{
	if (rotations_out >= 0)
		rotations_out++;
	if (rotations_out > length / 2)
		
}
