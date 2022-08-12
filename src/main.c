#include "../push_swap.h"

// clear && gcc -g main.c -Llibft_for_push_swap -lft && ./a.out 1 2 3 4 5 1
// clear && make re && ./push_swap
//["1", "4", "12", "2", "10", "6", "9", "13", "3", "11", "7", "15"],
//ARG="4 1"; ./push_swap $ARG | ./checker_linux $ARG

int	main(int argc, char **argv)
{
	t_push	*stack_a;
	t_push	*ptr_last_lis;

	stack_a = NULL;
	ptr_last_lis = NULL;
	check_if_small_or_big(argc);
	stack_a = create_linked_list(argc, argv, stack_a);
	check_multiples(stack_a);
	indexing(stack_a, argc);
	print_lists(stack_a, NULL);
	ptr_last_lis = make_lis(stack_a);
	stack_a = ft_lstlast_new(stack_a);
	push_out_and_in (stack_a, ptr_last_lis, argc);
}

void	indexing(t_push *stack_a, int argc)
{
	int		i;
	int		tmp;
	t_push	*first;
	t_push	*tmp_ptr;

	first = stack_a;
	i = 0;
	tmp = 0;
	while (i < argc)
	{
		stack_a = first;
		tmp = 0;
		while (stack_a)
		{
			if (stack_a->num > tmp && stack_a->index == -1)
			{
				tmp = stack_a->num;
				tmp_ptr = stack_a;
			}
			stack_a = stack_a->next;
		}
		tmp_ptr->index = i;
		i++;
	}
}
