#include "../push_swap.h"

t_push	*calculate_num_before(t_push *stack_a, t_push *stack_b, count_list *dif, int argc)
{
	int	stop = 0;
	int	i = 0;
	dif->rotate_before = 10000;
	while (stack_a->prev)	
	{
		if (stack_b->num - stack_a->num < dif->dif_plus && stack_b->num > stack_a->num)
		{
			dif->ptr_plus  = stack_a;
			dif->dif_plus = stack_b->num - stack_a->num;
			dif->rev_before = i;
		}
		stack_a = stack_a->prev;
		i++;
	}

	i = 0;
	while (stack_a->next)	
	{
		if (stack_b->num > stack_a->num && stack_b->num - stack_a->num <= dif->dif_plus)
		{
			dif->rotate_before= i;
		}
		stack_a = stack_a->next;
		i++;
	}

	/* int	length = ft_lstsize_new(stack_a);
	//DO SAME FOR OTHER FUNCTION
	if(length/ 2 < dif->rev_before)
		dif->rotate_before = dif->rev_before - argc / 2; */
}

t_push	*calculate_num_after(t_push *stack_a, t_push *stack_b, count_list *dif)
{
	int	stop = 0;
	int	i = 0;
	//rotate_after = 10000;
	while (stack_a->prev)	
	{
		if (stack_a->num - stack_b->num < dif->dif_minus && stack_a->num - stack_b->num > 0)
		{
			dif->ptr_minus  = stack_a;
			dif->dif_minus = stack_a->num -  stack_b->num;
			dif->rev_after = i;
		}
		stack_a = stack_a->prev;
		i++;
	}
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
	count_list	*dif;
	dif->dif_plus = 1000;
	dif->dif_minus = 1000;
	dif->ptr_plus= NULL;
	dif->ptr_minus= NULL;
	dif->rev_before = 10000;
	dif->rev_after = 10000;

	ft_printf("stack b testing \n\n");
	write(1, &stack_b->num,4);
	stack_b = ft_lstlast_new(stack_b);
	calculate_num_before(stack_a, stack_b, dif, argc);
	calculate_num_after(stack_a, stack_b, dif);


	//TESTING
	printf("closest -  %d\n", dif->dif_plus);
	t_push *temp = dif->ptr_plus;
	printf("num on stack a -  %d\n", temp->num);
	printf("revers rotations -  %d\n", dif->rev_before);
	printf("reg rotations -  %d\n", dif->rotate_before);
	printf("closest -  %d\n", dif->dif_minus);
	temp = dif->ptr_minus;
	if (dif->ptr_minus)
		printf("num on stack a -  %d\n", temp->num);

	//calc_num_rot(stack_a, stack_b, dif);
	return (dif);
}
