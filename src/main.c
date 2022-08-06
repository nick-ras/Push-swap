#include "../push_swap.h"

// clear && gcc -g main.c -Llibft_for_push_swap -lft && ./a.out 1 2 3 4 5 1
// clear && make re && ./push_swap
void	exit_statement_and_free(t_push *stack_a)
{
	t_push	*del;

	stack_a = ft_lstlast_new(stack_a);
	while (stack_a)
	{
		del = stack_a;
		stack_a = stack_a->prev;
		free(del);
		del = NULL;
	}

	ft_printf("freeing everything\n");
	exit(1);
}

int main(int argc, char **argv)
{
	t_push *stack_a = NULL;
	t_push *stack_b;
	t_push *longest = NULL;
	ft_printf("argc: %d\n", argc);
	check_if_small_or_big(argc);

	stack_a = create_linked_list(argc, argv, stack_a);
	stack_b = NULL;
	check_multiples(stack_a);

	if (argc <= 5)
		write(1, "small\n", 6);
	ft_printf("Beginning main loop\n");
	make_lis(stack_a);

	// finds last number in LIS
	longest = find_last_in_sequence(stack_a);

	// DEBUGGING showing whole sequence that need to be pushed to stack_b
	t_push *longest_debugging= longest;
	while (longest_debugging)
	{
		ft_printf("LIS number %d\n", longest_debugging->num);
		longest_debugging = longest_debugging->subs;
	}
	
	// rotates and pushed numbers
	stack_a = lis_pushing_to_b(stack_a, stack_b, longest, argc);
	ft_printf("\nlist sorted!\n");
}
