/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:44:41 by nickras           #+#    #+#             */
/*   Updated: 2022/08/23 10:14:16 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// clear && gcc -g main.c -Llibft_for_push_swap -lft && ./a.out 1 2 3 4 5 1
// clear && make re && ./push_swap
//["1", "4", "12", "2", "10", "6", "9", "13", "3", "11", "7", "15"],
//ARG="4 1"; ./push_swap $ARG | ./checker_linux $ARG
// nået til "4 1 3 6 5 7 8";

int	main(int argc, char **argv)
{
	t_push	*stack_a;
	t_count	*instr_2;
	t_push	*stack_b;

	stack_b = NULL;
	instr_2 = malloc(sizeof(t_count));
	stack_a = NULL;
	check_if_small_or_big(argc);
	stack_a = create_linked_list(argc, argv, stack_a);
	check_multiples(stack_a);
	indexing(stack_a, length_list(stack_a));
	if (argc <= 4)
		use_sa(stack_a, instr_2, argc);
	if (argc <= 6)
		five_numbers(stack_a, stack_b, instr_2);
	make_lis(stack_a);
	push_out_and_in (stack_a, argc, instr_2);
}

void	five_numbers(t_push *stack_a, t_push *stack_b, t_count *instr_2)
{
	t_push	*tmp;

	tmp = stack_a->next;
	stack_b = pb_first_push(stack_a, stack_b);
	stack_a = tmp;
	if (length_list(stack_a) == 4)
	{
		tmp = stack_a->next;
		stack_b = pb(stack_a, stack_b);
		stack_a = tmp;
	}
	stack_a = use_sa_5(stack_a, instr_2);
	sorting_back(stack_a, stack_b, instr_2);
}
