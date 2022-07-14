#include "../libft/libft.h"

// gcc -Wall -Werror -Wextra main.c -L../libft -lft && ./a.out 1 2 3 4 5

t_list	*ft_lstnew_new(char *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		new = NULL;
		return (new);
	}
	new->next = NULL;
	new->num = ft_atoi(content);
	if(new->num == 0 || new->num == -1)
	{
		write(1, "atoi returned error\n", 19);
		exit(1);
	}
	printf("Atoi: %d\n", new->num);
	return (new);
}

t_list	*ft_lstnew(int zero)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		new = NULL;
		return (new);
	}
	new->next = NULL;
	new->num = zero;
	return (new);
}

t_list *create_linked_list(int argc, char **argv)
{
	int i;
	t_list *ptr_first;
	t_list *stack_a;
	t_list	*ox2;

	if (argc <= 1)
		return (0);
	printf("argc: %d\n", argc);
	i = 1;
	stack_a = ft_lstnew_new(argv[i]);
	stack_a->previous = NULL;
	i++;
	ptr_first = stack_a;
	printf("ox2: %d and stirng: %s -- now loop->\n", ptr_first->num, argv[1]);
	while (i < argc)
	{
		stack_a->next = ft_lstnew_new(argv[i]);
		ox2 = stack_a;
		stack_a = stack_a->next;
		stack_a->previous = ox2;
		printf("in loop: index: %d contains: %d\n", i, stack_a->num);
		i++;
	}
	stack_a->next = NULL;
	while(i > 1)
	{
		printf("in loop: index: %d contains: %d\n", i, stack_a->num);
		stack_a = stack_a->previous;
		i--;
	}
	return(ptr_first);
}

t_list *create_linked_list(int argc, char **argv)
{
	int i;
	t_list *ptr_first;
	t_list *stack_a;
	t_list	*ox2;
	int	zero = 0;

	if (argc <= 1)
		return (0);
	printf("argc: %d\n", argc);
	i = 1;
	stack_a = ft_lstnew_new(argv[i]);
	stack_a->previous = NULL;
	i++;
	ptr_first = stack_a;
	printf("ox2: %d and stirng: %s -- now loop->\n", ptr_first->num, argv[1]);
	while (i < argc)
	{
		stack_a->next = ft_lstnew(int zero);
		//HOW IS LST NEW??
		ox2 = stack_a;
		stack_a = stack_a->next;
		stack_a->previous = ox2;
		printf("in loop: index: %d contains: %d\n", i, stack_a->num);
		i++;
	}
	stack_a->next = NULL;
	while(i > 1)
	{
		printf("in loop: index: %d contains: %d\n", i, stack_a->num);
		stack_a = stack_a->previous;
		i--;
	}
	return(ptr_first);
}

void sa(t_list *ox2)
{
	t_list *ox1;
	t_list *ox0;
	//t_list	temp_ox1;

	while (ox2->next)
		ox2 = ox2->next;
	ox1 = ox2->previous;
	ox0 = ox1->previous;
	ox0->next = ox2;

	ox2->next = ox1;
	ox1->previous = ox2;
	ox2->previous = ox1->previous;
	ox1->next = NULL;
}

void	commands(t_list *stack_a, t_list *stack_b, int command)
{
	if (command == 0)
		sa(stack_a);
	if (command == 1)
		sa(stack_b);
}

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int	command;

	command = 1;
	if(argc > 1000)
	{
		write(1, "argc too big", 12);
		return(1);
	}
	stack_a = create_linked_list(argc, argv);
	stack_b = create_empty_linked_list(argc, argv);
	//HOWTO make empty array efficient?
	commands(stack_a, stack_b, command);
	int i = 0;
	//ptr_first = ptr_first->previous;
	while(stack_a)
	{
		printf("--------------ptr = %d\n", stack_a->num);
		stack_a = stack_a->next;
		i++;
	}
	
	
}
