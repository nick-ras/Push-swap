/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:44:30 by nickras           #+#    #+#             */
/*   Updated: 2022/08/23 09:24:51 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	make_instructions(t_push *stack_a, t_push *stack_b, \
t_count *instructions)
{
	t_push	*first;

	initialize_instructions_struct(instructions);
	first = stack_a;
	while (stack_b)
	{
		stack_a = first;
		instructions->stack_a_pos = 0;
		instructions->dif = -2147483648;
		instructions->dif_bg = 2147483647;
		while (stack_a)
		{
			make_instructions_subfunction(stack_a, stack_b, instructions);
			stack_a = stack_a->next;
			instructions->stack_a_pos++;
		}
		if (abs_val(instructions->ra_tmp) + abs_val(instructions->rr_tmp) \
		< abs_val(instructions->ra) + abs_val(instructions->rr))
		{
			instructions->ra = instructions->ra_tmp;
			instructions->rr = instructions->rr_tmp;
		}
		if (abs_val(instructions->ra_bg_tmp) + abs_val(instructions->rr_bg_tmp) \
		< abs_val(instructions->ra_bg) + abs_val(instructions->rr_bg))
		{
			instructions->ra_bg = instructions->ra_bg_tmp;
			instructions->rr_bg = instructions->rr_bg_tmp;
		}
		if (stack_b->next)
			instructions->stack_b_pos++;
		stack_b = stack_b->next;
	}
}

//you could throw it into two dif function depending if its plus or minus
void	make_instructions_subfunction(t_push *stack_a, t_push *stack_b, \
t_count *instructions)
{
	int	a_min_b;

	a_min_b = stack_a->num - stack_b->num;
	if (a_min_b < 0)
	{
		if (a_min_b > instructions->dif)
			set_commands(stack_a, stack_b, instructions);
	}
	else if (a_min_b > 0)
	{
		if (a_min_b < instructions->dif_bg)
			set_commands_bg(stack_a, stack_b, instructions);
	}
}

int	fastest_route(int rotations, t_push *stack_a)
{
	int	length;

	length = length_list(stack_a);
	if (rotations > length / 2 && rotations > 0)
		rotations = -length + rotations;
	if (rotations > length / 2 && rotations < 0)
		rotations = length + rotations;
	return (rotations);
}
