/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:25:10 by nickras           #+#    #+#             */
/*   Updated: 2022/08/24 10:12:25 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// updates the commands in the struct that keeps the calculations for the fewest
//number of commands to get an element from stack b back to stack a. compared to.
//compared to "set_commands_bg" then this one finds the closest bigger element
//on stack a, and puts the stack b element before it
void	set_commands(t_push *stack_a, t_push *stack_b, t_count *instructions)
{
	instructions->rr_tmp = fastest_route(instructions->stack_b_pos, stack_b);
	instructions->ra_tmp = fastest_route(instructions->stack_a_pos + 1 \
	- fastest_route(instructions->stack_b_pos, stack_b), stack_a);
	instructions->dif = stack_a->num - stack_b->num;
}

//Same is "set_command" but finds the closest small element on stack a, and puts 
//the stack b element after it
void	set_commands_bg(t_push *stack_a, t_push *stack_b, t_count *instructions)
{
	instructions->ra_bg_tmp = fastest_route(instructions->stack_a_pos, stack_a) \
	- fastest_route(instructions->stack_b_pos, stack_b);
	instructions->dif_bg = stack_a->num - stack_b->num;
	instructions->rr_bg_tmp = fastest_route(instructions->stack_b_pos, stack_b);
}

//This function executes the calculations saved in the struct, and gets an element
//from stack b to stack a, while making sure stack a is still sorted
//Return: if stack b is not empty, it returns first in stack b, otherwise first in stack a
t_push	*execute_instructions(t_push *stack_a, t_push *stack_b, \
t_count *instructions)
{
	stack_a = go_to_first(stack_a);
	while (instructions->rr > 0)
	{
		write(1, "rr\n", 3);
		stack_a = r(stack_a);
		stack_b = r(stack_b);
		instructions->rr--;
	}
	while (instructions->rr < 0)
	{
		write(1, "rrr\n", 4);
		stack_a = rr(stack_a);
		stack_b = rr(stack_b);
		instructions->rr++;
	}
	stack_a = execute_ra(stack_a, instructions);
	if (stack_b)
		return (pa(stack_a, stack_b));
	return (stack_a);
}

//subfunction of execute_instructions, that rotates a
t_push	*execute_ra(t_push *stack_a, t_count *instructions)
{
	while (instructions->ra > 0)
	{
		write(1, "ra\n", 3);
		stack_a = r(stack_a);
		instructions->ra--;
	}
	while (instructions->ra < 0)
	{
		write(1, "rra\n", 4);
		stack_a = rr(stack_a);
		instructions->ra++;
	}
	return (stack_a);
}

//if two numbers are one index apart "ex index 3 and index 4", it puts them on top of lists
//and uses swap command, so the switch place
t_push	*execute_stack_a(t_push *stack, t_count *instr_2)
{
	instr_2->ra = fastest_route(instr_2->stack_a_pos, go_to_first(stack));
	stack = execute_instructions(go_to_first(stack), NULL, instr_2);
	stack = sa(stack);
	return (stack);
}
