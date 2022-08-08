#include "../push_swap.h"

t_push	*execute_instructions(t_push *last_main,t_push *stack_b, t_count *instructions)
{
	t_push		*prev_b;

	while (instructions->rrr > 0)
	{
		commands(last_main, stack_b, 7);
		printf("abc\n");
		instructions->rrr--;

	}
	while (instructions->rrr < 0)
	{
		commands(last_main, stack_b, 7);
		printf("abc\n");
		instructions->rrr++;

	}
	while (instructions->lw_ra > 0)
	{
		commands(last_main, stack_b, 7);
		printf("abc\n");
		instructions->lw_ra--;
	}
	while (instructions->lw_ra < 0)
	{
		commands(last_main, stack_b, 7);
		printf("abc\n");
		instructions->lw_ra++;
	}
	stack_b = ft_lstlast_new(stack_b);
	prev_b = stack_b->prev;
	commands(last_main, stack_b, 3);
	printf("abc\n");
	return (prev_b);
}
