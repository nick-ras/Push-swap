/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:28:01 by nickras           #+#    #+#             */
/*   Updated: 2022/08/23 09:28:10 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_low_to_high(t_push *stack, t_count	*instr_2)
{
	t_push	*first;

	stack = go_to_first(stack);
	first = stack;
	instr_2->ra = 0;
	while (stack)
	{
		if (stack->index == 0)
			break ;
		stack = stack->next;
		instr_2->ra++;
	}
	instr_2->ra = fastest_route(instr_2->ra, stack);
	first = execute_instructions(first, NULL, instr_2);
	free(instr_2);
	instr_2 = NULL;
	exit_statement_and_free(stack, 0);
}

int	sort_check_while_pb(t_push *stack_a)
{
	t_push	*next_nb;

	while (stack_a->prev)
		stack_a = stack_a->prev;
	while (stack_a->next)
	{
		next_nb = stack_a->next;
		if (stack_a->index + 1 != next_nb->index)
		{
			if (next_nb != lowest_index(go_to_first(stack_a)))
				return (0);
		}
		stack_a = next_nb;
	}
	return (1);
}
