#include "../push_swap.h"

// clear && gcc -g main.c -Llibft_for_push_swap -lft && ./a.out 1 2 3 4 5 1
// clear && make re && ./push_swap
//["1", "4", "12", "2", "10", "6", "9", "13", "3", "11", "7", "15"],

int	main(int argc, char **argv)
{
	t_push	*stack_a;
	t_push	*ptr_last_lis;

	stack_a = NULL;
	ptr_last_lis = NULL;
	check_if_small_or_big(argc);
	stack_a = create_linked_list(argc, argv, stack_a);
	check_multiples(stack_a);

	ptr_last_lis = make_lis(stack_a);
	push_out_and_in (stack_a, ptr_last_lis, argc);
}
