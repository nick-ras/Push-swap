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
	ft_printf("argc: %d\n", argc);
	check_if_small_or_big(argc);
	stack_a = create_linked_list(argc, argv, stack_a);
	check_multiples(stack_a);

	if (argc <= 5)
		write(1, "small\n", 6);
	ptr_last_lis = make_lis(stack_a);
	push_out_and_in (stack_a, ptr_last_lis, argc);
	ft_printf("\nend of main!\n");
}

// void	final_rotations(t_push *stack_a, t_count *final_instructions)
// {
// 	t_push	*tmp;
// 	int		rotations;
// 	t_push	*tmp_count;
	
// 	tmp = ft_lstlast_new(stack_a);
// 	while (tmp)
// 	{
// 		if (tmp->num < final_instructions->lowest)
// 		{
// 			final_instructions->lowest = tmp->num;
// 			final_instructions->lowest_ptr = tmp;
// 		}
// 		tmp = tmp->prev;
// 	}
// 	rotations = 0;
// 	tmp_count = ft_lstlast_new(stack_a);
// 	while (tmp_count->prev)
// 	{
// 		rotations++;
// 		if (tmp_count == final_instructions->lowest_ptr)
// 			break ;
// 		tmp_count = tmp_count->prev;
// 	}
// 	final_initialize_instructions_struct(final_instructions);
// 	final_instructions->ra = fastest_route(rotations, stack_a);
// 	execute_instructions(stack_a, NULL, final_instructions);
// }