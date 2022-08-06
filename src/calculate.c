#include "../push_swap.h"

int	half(int rotations, t_push *stack_a)
{
	int	length;

	length = ft_lstsize_new(stack_a);
	if (rotations > (length / 2) && rotations - length / 2 != 1)
		rotations = -length + rotations - 1;
	return(rotations);
}

count_list	*calculating_and_sorting_back_to_a(t_push *stack_a, t_push *stack_b)
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

	//lav outer loop så der tjekkes for hvert tal nedadgående i b
	//while(stack_b->prev)

	//check rotations to get lower on top of a (by check smallest dif)
	while (stack_a->prev)	
	{
		// + = a > b
		nb_dif = stack_b->num - stack_a->num;
		//iif dif is smaller then stored value and dif is > 0
		if (nb_dif < dif->dif_a_lw && nb_dif > 0)
		{
		//the iteration becomes dif->dif
			dif->dif_a_lw = nb_dif;
			rotations = half(rotations, stack_a); //if rotations > half argc, then measure rra instead of ra
			//HERHERHEREHERE
			//HERHERHEREHERE position, check på papir hvordan du fåropad (ra) eller nedad rotation (rra), whichever er hurtigst (men måske udlign med b's rotations først?????????? for hvis den er opad (rra) (skal roteres opad) så kan den lægges sammen med rrb så det blivver rrr
			dif->dif_a_lw_pos = rotations;
		}
		stack_a = stack_a->prev;
		rotations++;
		printf("dif_a_lw_pos     %d\ndif_a_low     %d\nrandom    %d\n", dif->dif_a_lw_pos, dif->dif_a_lw, first->len);
	}

	while (stack_a->prev)	
	{
		// + = a > b
		nb_dif = stack_b->num - stack_a->num;
		//iif dif is smaller then stored value and dif is > 0
		if (nb_dif < dif->dif_a_lw && nb_dif > 0)
		{
		//the iteration becomes dif->dif
			dif->dif_a_lw = nb_dif;
			rotations = half(rotations, stack_a); //if rotations > half argc, then measure rra instead of ra
			//HERHERHEREHERE
			//HERHERHEREHERE position, check på papir hvordan du fåropad (ra) eller nedad rotation (rra), whichever er hurtigst (men måske udlign med b's rotations først?????????? for hvis den er opad (rra) (skal roteres opad) så kan den lægges sammen med rrb så det blivver rrr
			dif->dif_a_lw_pos = rotations;
		}
		stack_a = stack_a->prev;
		rotations++;
		printf("dif_a_lw_pos     %d\ndif_a_low     %d\nrandom    %d\n", dif->dif_a_lw_pos, dif->dif_a_lw, first->len);
	}
	//check rotations to get bigger on top of a
	// compare how many rb or rrb that needs, and combine with ra or rra into rr or rrr. if dif_a_lw_pos is plus then its ra and if minus its rra.
	//calculate_num_after(stack_a, stack_b, dif);																																																
	return (dif);
}
