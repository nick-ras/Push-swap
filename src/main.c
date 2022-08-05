#include "../push_swap.h"

// clear && gcc -g main.c -Llibft_for_push_swap -lft && ./a.out 1 2 3 4 5 1
//./push_swap 1 4 12 2 10 6 9 13 3 11 7 15

void check_multiples(t_push *first)
{
	t_push *outer;
	t_push *inner_up;

	outer = first;
	while (outer->next)
	{
		inner_up = outer->next;
		while (inner_up)
		{
			if (inner_up->num == outer->num)
			{
				write(1, "multiples!\n", 11);
				exit_statement_and_free(first);
			}
			inner_up = inner_up->next;
		}
		outer = outer->next;
	}
}

void	check_if_small_or_big(int argc)
{
	if (argc > 1000 || argc < 2)
	{
		write(1, "argc too big or small!\n", 23);
		exit (1);
	}

}

void	make_lis(t_push *stack_a)
{
	t_push *outer = stack_a;
	t_push *inner = stack_a;
	outer = stack_a;
	while (outer)
	{
		inner = stack_a;
		while (inner && inner != outer)
		{
			if (inner->num < outer->num)
			{
				if (inner->len + 1 >= outer->len)
				{
					outer->len = inner->len + 1;
					outer->subs = inner;
				}
			}
			inner = inner->next;
		}
		outer = outer->next;
	}
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
