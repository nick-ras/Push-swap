#include "../push_swap.h"

t_push  *put_back(t_push *last_main,t_push *stack_b, count_list *recipe)
{   
    t_push  *prev_b;

    while 
    (recipe->both > 0)
    {
        commands(last_main, stack_b, 7);
        printf("abc\n");
        recipe->both--;

    }
     while (recipe->both < 0)
    {
        commands(last_main, stack_b, 7);
        printf("abc\n");
        recipe->both++;

    }
    while (recipe->lw_pos > 0)
    {
        commands(last_main, stack_b, 7);
        printf("abc\n");
        recipe->lw_pos--;
    }
    while (recipe->lw_pos < 0)
    {
        commands(last_main, stack_b, 7);
        printf("abc\n");
        recipe->lw_pos++;
    }
    stack_b = ft_lstlast_new(stack_b);
    prev_b = stack_b->prev;
    commands(last_main, stack_b, 3);
    printf("abc\n");
    return (prev_b);
}
