#include "push_swap.h"

t_node *new_node(int value)
{
    t_node *n = malloc(sizeof(t_node));
    n->value = value;
    n->next = NULL;
    return n;
}

void add_back(t_node **stack, t_node *new)
{
    t_node *tmp;

    if (!*stack)
    {
        *stack = new;
        return;
    }
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

int stack_size(t_node *stack)
{
    int i = 0;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return i;
}