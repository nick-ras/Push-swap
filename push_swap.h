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
	struct s_push	*prev;
	struct s_push	*next;
	struct s_push	*subs;
}	t_push;

typedef struct counter_list
{
	int	bg;
	int	lw;
	int	bg_pos;
	int	lw_ra;
	int	b;
	int	rrr;
	//all most be used with fastest_route
}	t_count;

typedef struct rotation
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_rotations;

int		main(int argc, char **argv);
void	print_lists(t_push *stack_a, t_push *stack_b);

void	check_multiples(t_push *first);
void	check_if_small_or_big(int argc);
void	exit_statement_and_free(t_push *stack_a);

t_push	*ft_lstnew_new(char *content, t_push *stack_a);
int		length_list(t_push *lst);
t_push	*create_linked_list(int argc, char **argv, t_push *stack_a);

//Commands
void	sa(t_push *ox2);
void	pa(t_push *stack_a, t_push *stack_b);
t_push	*pb(t_push *stack_a, t_push *stack_b);
void	ra(t_push *stack_a);
void	rb(t_push *stack_b);

//commands
t_push	*rra(t_push *stack_a);
void rrb(t_push *stack_b);
t_push *commands(t_push *stack_a, t_push *stack_b, int command);

//libft
t_push	*ft_lstlast_new(t_push *lst);
int	ft_atoi_push(char *str, t_push *stack_a);

int sort_check(t_push *stack_a, t_push *stack_b);
int numbers_in_order(t_push *first);

void	make_lis(t_push *stack_a);
t_push *find_last_in_sequence(t_push *stack_a);
void	push_lis_leftover(t_push *stack_a, \
t_push *longest, int argc);

void	calculate_num_before(t_push *stack_a, t_push *stack_b, t_count *dif, int argc);
int	fastest_route(int b_dif, t_push *stack_a);
t_count	*make_instructions(t_push *stack_a, t_push *stack_b);

t_push  *put_back(t_push *last_main,t_push *stack_b, t_count *instructions);

#endif