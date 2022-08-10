#include "../push_swap.h"

t_push	*make_lis(t_push *stack_a)
{
	t_push	*outer;
	t_push	*inner;
	t_push	*ptr_lis_last;

	ptr_lis_last = NULL;
	outer = stack_a;
	inner = stack_a;
	while (outer)
	{
		inner = stack_a;
		while (inner && inner != outer)
		{
			if (inner->num < outer->num)
			{
				if (inner->len + 1 >= outer->len)
					ptr_lis_last = set_subsequent(outer, inner, ptr_lis_last);
			}
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (ptr_lis_last);
}

void	*set_subsequent(t_push *outer, t_push *inner, void *ptr_lis_last)
{
	outer->len = inner->len + 1;
	outer->subs = inner;
	ptr_lis_last = outer;
	return (ptr_lis_last);
}