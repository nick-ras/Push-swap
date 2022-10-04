/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:44:27 by nickras           #+#    #+#             */
/*   Updated: 2022/08/24 10:19:05 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//initialize struct the holds the calculations for the element on stack b, that uses
//the fewest amount of commands (rotate, swap and push command) to be sorted back into stack a,
//so ex if stack a is 1, 4, 7, and the numbers on stack b is 3, then it lands between 1 and 4 on 
//stack a
void	initialize_instructions_struct(t_count *instructions)
{
	instructions->dif = -2147483648;
	instructions->dif_bg = 2147483647;
	instructions->ra = 1000;
	instructions->ra_tmp = 1000;
	instructions->rr = 1000;
	instructions->rr_tmp = 1000;
	instructions->ra_bg = 1000;
	instructions->ra_bg_tmp = 1000;
	instructions->rr_bg = 1000;
	instructions->rr_bg_tmp = 1000;
	instructions->stack_b_pos = 0;
	instructions->stack_a_pos = 0;
	instructions->lowest = -2147483648;
}

//resets the calculations everytime a number is sorted back, so new
//calculations can be made for next number
void	reset_count_rotations(t_count *instructions)
{
	instructions->dif = 0;
	instructions->dif_bg = 0;
	instructions->ra = 0;
	instructions->ra_tmp = 0;
	instructions->rr = 0;
	instructions->rr_tmp = 0;
	instructions->ra_bg = 0;
	instructions->ra_bg_tmp = 0;
	instructions->rr_bg = 0;
	instructions->rr_bg_tmp = 0;
	instructions->stack_b_pos = 0;
	instructions->stack_a_pos = 0;
	instructions->lowest = -2147483648;
}

//resets starting difference to max difference
void	extra_initialization(t_count *instr)
{
	instr->stack_a_pos = 0;
	instr->dif = -2147483648;
	instr->dif_bg = 2147483647;
}
