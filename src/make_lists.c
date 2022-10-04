/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:44:45 by nickras           #+#    #+#             */
/*   Updated: 2022/09/09 13:33:46 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


//creates a new struct for the link list, and then convert command line argument to an integer
//and puts it into the struct
t_push	*ft_lstnew_new(char *content, t_push *stack_a, t_count *instr_2)
{
	t_push	*new;

	new = malloc(sizeof(t_push));
	if (!new)
	{
		new = NULL;
		exit_statement_and_free(stack_a, 1, instr_2);
	}
	new->next = NULL;
	new->prev = stack_a;
	new->len = 1;
	new->subs = NULL;
	new->index = -1;
	if (ft_atoi(content) == 0 || ft_atoi(content) == -1)
		exit_statement_and_free(stack_a, 1, instr_2);
	new->num = ft_atoi_push(content, new, instr_2);
	return (new);
}

// This function uses subfunction to create a new struct and convert command line argument to 
//an integer. It invokes subfunction as long as there is still more command line arguments to put into linked list.
//It connects the current stack with the new struct so its a double linked lists
t_push	*create_linked_list(int argc, \
char **argv, t_push *stack_a, t_count *instr_2)
{
	int		i;
	t_push	*ptr_first;

	i = 1;
	stack_a = ft_lstnew_new(argv[i], stack_a, instr_2);
	stack_a->prev = NULL;
	i++;
	ptr_first = stack_a;
	while (i < argc)
	{
		stack_a->next = ft_lstnew_new(argv[i], stack_a, instr_2);
		stack_a = stack_a->next;
		i++;
	}
	stack_a->next = NULL;
	return (ptr_first);
}
