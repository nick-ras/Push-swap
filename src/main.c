#include "../push_swap.h"

// clear && gcc -g main.c -Llibft_for_push_swap -lft && ./a.out 1 2 3 4 5 1
// clear && make re && ./push_swap
//["1", "4", "12", "2", "10", "6", "9", "13", "3", "11", "7", "15"],
//ARG="4 1"; ./push_swap $ARG | ./checker_linux $ARG
// nået til "4 1 3 6 5 7 8";

int	main(int argc, char **argv)
{
	t_push	*stack_a;

	stack_a = NULL;
	check_if_small_or_big(argc);
	stack_a = create_linked_list(argc, argv, stack_a);
	check_multiples(stack_a);
	indexing(stack_a, argc);
	if (argc <= 15)
		stack_a = check_2_at_top(stack_a);
	make_lis(stack_a);
	push_out_and_in (stack_a, argc);

}
