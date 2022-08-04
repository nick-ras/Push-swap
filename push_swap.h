#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include "./printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_push
{
	int	num;
	int	len;
	struct s_push	*prev;
	struct s_push	*next;
	struct s_push	*subs;
}	t_push;

typedef struct counter_list
{
	int	dif_a_bg;
	int	dif_a_lw;
	int	dif_a_bg_pos;
	int	dif_a_lw_pos;
	int	dif_b;
	//all most be used with half
}	count_list;

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
}	rotations;

t_push *ft_lstnew_new(char *content, t_push *stack_a);
int	ft_lstsize_new(t_push *lst);
t_push *create_linked_list(int argc, char **argv, t_push *stack_a);

void sa(t_push *ox2);
void pa(t_push *stack_a, t_push *stack_b);
t_push	*pb(t_push *stack_a, t_push *stack_b);
void ra(t_push *stack_a);
void rb(t_push *stack_b);

t_push	*rra(t_push *stack_a);
void rrb(t_push *stack_b);
t_push *commands(t_push *stack_a, t_push *stack_b, int command);

t_push	*ft_lstlast_new(t_push *lst);
t_push *find_last_in_sequence(t_push *stack_a);
int sort_check(t_push *stack_a);
int numbers_in_order(t_push *first);

int	ft_atoi_push(char *str, t_push *stack_a);

void	exit_statement_and_free(t_push *stack_a);
void	check_multiples(t_push *first);
void	check_if_small_or_big(int argc);

void	make_lis(t_push *stack_a);
void	calculate_num_before(t_push *stack_a, t_push *stack_b, count_list *dif, int argc);
void	calculate_num_after(t_push *stack_a, t_push *stack_b, count_list *dif);
int	half(int b_dif, int argc);

count_list	*calculating_and_sorting_back_to_a(t_push *stack_a, t_push *stack_b, int argc);
t_push	*lis_pushing_to_b(t_push *stack_a, t_push *stack_b, t_push *longest, int argc);
int main(int argc, char **argv);
#endif