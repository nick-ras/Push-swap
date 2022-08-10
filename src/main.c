#include "../push_swap.h"

// clear && gcc -g main.c -Llibft_for_push_swap -lft && ./a.out 1 2 3 4 5 1
// clear && make re && ./push_swap
//["1", "4", "12", "2", "10", "6", "9", "13", "3", "11", "7", "15"],

void	print_lists(t_push *stack_a, t_push *stack_b)
{
	while (stack_a)
	{
		ft_printf("a checking from last =   %d\n", stack_a->num);
		stack_a = stack_a->prev;
	}
	while (stack_b)
	{
		ft_printf("b checking from last =   %d\n", stack_b->num);
		stack_b = stack_b->prev;
	}
}

int	absolute_value(int value)
{
	if (value < 0)
		return (-value);
	else
		return (value);
}

int	main(int argc, char **argv)
{
	t_push	*stack_a;
	t_push	*longest;

	stack_a = NULL;
	longest = NULL;
	ft_printf("argc: %d\n", argc);
	check_if_small_or_big(argc);

	stack_a = create_linked_list(argc, argv, stack_a);
	check_multiples(stack_a);

	if (argc <= 5)
		write(1, "small\n", 6);
	ft_printf("Beginning main loop\n");
	make_lis(stack_a);

	// finds last number in LIS
	longest = find_last_in_sequence(stack_a);

	// rotates and pushed numbers
	sorting_pipeline (stack_a, longest, argc);
	ft_printf("\nend of main!\n");
}
