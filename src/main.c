/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:44:41 by nickras           #+#    #+#             */
/*   Updated: 2022/08/25 14:46:58 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// clear && gcc -g main.c -Llibft_for_push_swap -lft && ./a.out 1 2 3 4 5 1
// clear && make re && ./push_swap
//["1", "4", "12", "2", "10", "6", "9", "13", "3", "11", "7", "15"],
//ARG="4 1"; ./push_swap $ARG | ./checker_linux $ARG
// nået til "4 1 3 6 5 7 8";

//Takes command line arguments, convert them to integers and sorts them by ascending order.
//the tasks had a lot of specific requirement which made it more difficult to implement this
//sorting program. I can only use two stacks, and only use the commands from the "commands_.." files.
//-----------THE TASK is to use the lowest number of commands to sort the numbers----------------
//it return the lists of commands that need to be executed (which is about 6000 commands for 500 elements)
int	main(int argc, char **argv)
{
	t_push	*stack_a;
	t_count	*instr_2;
	t_push	*stack_b;

	is_integers(argv);
	is_not_only_minus(argv);
	stack_b = NULL;
	instr_2 = malloc(sizeof(t_count));
	reset_count_rotations(instr_2);
	stack_a = NULL;
	check_if_small_or_big(argc, instr_2);
	stack_a = create_linked_list(argc, argv, stack_a, instr_2);
	check_multiples(stack_a, instr_2);
	indexing(stack_a, length_list(stack_a));
	sort_check_full(stack_a, instr_2, argc);
	if (argc <= 4)
		sort_3_numbers(stack_a, instr_2, argc);
	if (argc <= 6)
		sort_five_numbers(stack_a, stack_b, instr_2);
	make_lis(stack_a);
	push_out_and_in (stack_a, argc, instr_2);
}
