#include "../push_swap.h"

int	half(int rotations, int argc)
{
	if (rotations > (argc / 2) && rotations -  argc / 2 != 1)
		rotations = -argc + rotations - 1;
	return(rotations);
}

/* calc_num_rot(stack_a, stack_b, dif)
{
	while (stack_a)
	{
		if (stack_a)
	}
} */

count_list	*calculating_and_sorting_back_to_a(t_push *stack_a, t_push *stack_b, int argc)
{
	//void	*best_strategy;
	count_list	*dif = malloc(sizeof(count_list));
	t_push	*first = ft_lstlast_new(stack_a);

	//set again every loop
	dif->dif_a_bg = 1000;
	dif->dif_a_lw = 1000;
	dif->dif_a_bg_pos = 1000;
	dif->dif_a_lw_pos = 1000;
	dif->dif_b = 1000;
	int	nb_dif;
	int	rotations = 0;
	
	stack_b = ft_lstlast_new(stack_b);
	//check rotations to get lower on top of a (by check smallest dif)
	while (stack_a->prev)	
	{
		// + = a > b
		nb_dif = stack_a->num - stack_b->num;
		//iif dif is smaller then stored value and dif is > 0
		if (nb_dif < dif->dif_a_bg && nb_dif > 0)
		{
		//the iteration becomes dif->dif
			dif->dif_a_lw = nb_dif;
			rotations = half(rotations, argc); //if rotations > half argc, then measure rra instead of ra
			dif->dif_a_lw_pos = rotations;
		}
		stack_a = stack_a->prev;
		rotations++;
		printf("dif_a_lw_pos %d\n, nb_dif%d\n random%d", dif->dif_a_lw, dif->dif_a_lw_pos, first->len);
	}
	//check rotations to get bigger on top of a

	// compare how many rb or rrb that needs, and combine with ra or rra into rr or rrr. if dif_a_lw_pos is plus then its ra and if minus its rra.



	//calculate_num_after(stack_a, stack_b, dif);
	//calc_num_rot(stack_a, stack_b, dif);
	return (dif);
}
