/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:23:03 by nickras           #+#    #+#             */
/*   Updated: 2022/08/23 10:20:52 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// The same as the indexing function, but this time it updates the "index_tmp" field and not "index" field
void	indexing_partial(t_push *stack_a, int length)
{
	int		tmp;
	t_push	*first;
	t_push	*tmp_ptr;

	first = stack_a;
	clear_partial_index(stack_a);
	while (length--)
	{
		stack_a = first;
		tmp = -2147483648;
		while (stack_a)
		{
			if (stack_a->num > tmp && stack_a->index_tmp == -1)
			{
				tmp = stack_a->num;
				tmp_ptr = stack_a;
			}
			if (stack_a->next == NULL)
				break ;
			stack_a = stack_a->next;
		}
		tmp_ptr->index_tmp = length;
	}
}

// sets all the "index_tmp" fields in the linked lists to "-1"
void	clear_partial_index(t_push *stack)
{
	stack = go_to_first(stack);
	while (stack)
	{
		stack->index_tmp = -1;
		stack = stack->next;
	}
}

//finds the highest index in the "index" field
int	highest_index(t_push *stack)
{
	int		tmp;

	tmp = -2147483648;
	while (stack)
	{
		if (stack->index >= tmp)
			tmp = stack->index;
		stack = stack->next;
	}
	return (tmp);
}

//takes a linked list elements and goes to the top of the stack
t_push	*go_to_first(t_push *stack)
{
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}
