#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include "./printf/ft_printf.h"

typedef struct s_push
{
	int				num;
	int				len;
	int				index;
	struct s_push	*prev;
	struct s_push	*next;
	struct s_push	*subs;
}	t_push;

typedef struct counter_list
{
	int		stack_a_pos;
	int		stack_b_pos;
	int		dif;
	int		dif_bg;
	int		ra;
	int		rr;
	int		ra_bg;
	int		rr_bg;
	t_push	*lowest_ptr;
	int		lowest;
}	t_count;

int		main(int argc, char **argv);
void	indexing(t_push *stack_a, int argc);
t_push	*create_linked_list(int argc, char **argv, t_push *stack_a);

//helpers
int		length_list(t_push *lst);
int		absolute_value(int value);
void	exit_statement_and_free(t_push *stack_a);

//checks
void	check_multiples(t_push *first);
void	check_if_small_or_big(int argc);
int		sort_check(t_push *stack_a, int argc);
int		numbers_in_order(t_push *first);


//commands
t_push	*sa(t_push *stack_a);
t_push	*pa(t_push *stack_a, t_push *stack_b);
t_push	*pb(t_push *stack_a, t_push *stack_b);
t_push	*pb_first_push(t_push *stack_a, t_push *stack_b);
t_push	*r(t_push *stack);
t_push	*rr(t_push *stack);

//libft
t_push	*ft_lstlast_new(t_push *lst);
int		ft_atoi_push(char *str, t_push *stack_a);
t_push	*ft_lstnew_new(char *content, t_push *stack_a);

//make longest increasing subsequence and sorting pipeline
void	make_lis(t_push *stack_a);
void	clean_lis(t_push *stack_a);
t_push	*check_2_at_top(t_push *stack);
t_push	*find_last_in_sequence(t_push *stack_a);

//sorting
void	push_out_and_in(t_push *stack_a, int argc);
void	sorting_back(t_push *stack_a, t_push *stack_b);

//making instructions
int		does_is_use_less_commands(t_push *stack_a, t_count *instructions);
void	make_instructions(t_push *stack_a, t_push \
*stack_b, t_count *instructions);
int		fastest_route(int b_dif, t_push *stack_a);
void	calculate_num_before(t_push *stack_a, \
t_push	*stack_b, t_count *dif, int argc);
void	set_commands(t_push *stack_a, t_push *stack_b, t_count *instructions);
void	set_commands_bg(t_push *stack_a, t_push *stack_b, \
t_count *instructions);

void	print_lists(t_push *stack_a, t_push *stack_b);
void	initialize_instructions_struct(t_count *instructions);void	initialize_same_stack(t_count *instructions);
void	final_initialize_instructions_struct(t_count *instructions);
void	make_instructions_subfunction(t_push *stack_a, t_push *stack_b, \
t_count *instructions);

//executes instructions, return stack_b last
t_push	*execute_instructions(t_push *last_main, \
t_push *stack_b, t_count *instructions);
t_push	*execute_instructions_bg(t_push *stack_a, t_push *stack_b, \
t_count *instructions);

#endif