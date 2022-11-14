/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:44:30 by nickras           #+#    #+#             */
/*   Updated: 2022/08/23 09:43:58 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Calculates the amount of commands needed to push a number on stack b back to its
place on stack a, which is already sorted. It makes sure the stack a is still sorted
and its calculated the commands it need to put it before the closest bigger number
or commands needed to put it after the closest lower number. */
void	make_instructions(t_push *stack_a, t_push *first, t_push \
*stack_b, t_count *instr)
{
	initialize_instructions_struct(instr);
	while (stack_b)
	{
		stack_a = first;
		extra_initialization(instr);
		while (stack_a)
			stack_a = make_instructions_subfunction(stack_a, stack_b, instr);
		if (abs_val(instr->ra_tmp) + abs_val(instr->rr_tmp) \
		< abs_val(instr->ra) + abs_val(instr->rr))
		{
			instr->ra = instr->ra_tmp;
			instr->rr = instr->rr_tmp;
		}
		if (abs_val(instr->ra_bg_tmp) + abs_val(instr->rr_bg_tmp) \
		< abs_val(instr->ra_bg) + abs_val(instr->rr_bg))
		{
			instr->ra_bg = instr->ra_bg_tmp;
			instr->rr_bg = instr->rr_bg_tmp;
		}
		if (stack_b->next)
			instr->stack_b_pos++;
		stack_b = stack_b->next;
	}
}

//This commands updates the instructions if the amount of commands needed in the the new calculations are lower then
//the current "winning" calculation saved int he struct "instr"
t_push	*make_instructions_subfunction(t_push *stack_a, t_push *stack_b, \
t_count *instr)
{
	int	a_min_b;

	a_min_b = stack_a->num - stack_b->num;
	if (a_min_b < 0)
	{
		if (a_min_b > instr->dif)
			set_commands(stack_a, stack_b, instr);
	}
	else if (a_min_b > 0)
	{
		if (a_min_b < instr->dif_bg)
			set_commands_bg(stack_a, stack_b, instr);
	}
	instr->stack_a_pos++;
	return (stack_a->next);
}

//It calculates whether its faster to use rotation of reverse rotation
//when it needs to get an element to the top of the list
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
