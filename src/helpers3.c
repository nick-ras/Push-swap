/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:28:01 by nickras           #+#    #+#             */
/*   Updated: 2022/08/24 09:10:07 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//check if command line arguments is integers
void	is_integers(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-' \
			&& argv[i][j] != 32)
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

//checks if command line argument is "-" which is not an integer
void	is_not_only_minus(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
			{
				if (!ft_isdigit(argv[i][j + 1]))
				{
					write(1, "Error\n", 6);
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

//When everything is on stack a, and is sorted, it rotates linked list
//until top of stack a is index 0
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
	exit_statement_and_free(first, 0, instr_2);
}
