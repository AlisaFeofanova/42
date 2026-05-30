#include "push_swap.h"
#include <stdio.h>

void sa(t_node **a)
{
    t_node *first;
    t_node *second;

    if (!*a || !(*a)->next)
        return;
    first = *a;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *a = second;

    write(1, "sa\n", 3);
}

void pb(t_node **a, t_node **b)
{
    t_node *tmp;

    if (!*a)
        return;
    tmp = *a;
    *a = (*a)->next;

    tmp->next = *b;
    *b = tmp;

    write(1, "pb\n", 3);
}

void pa(t_node **a, t_node **b)
{
    t_node *tmp;

    if (!*b)
        return;
    tmp = *b;
    *b = (*b)->next;

    tmp->next = *a;
    *a = tmp;

    write(1, "pa\n", 3);
}

void ra(t_node **a)
{
    t_node *first;
    t_node *last;

    if (!*a || !(*a)->next)
        return;

    first = *a;
    *a = first->next;

    last = *a;
    while (last->next)
        last = last->next;

    last->next = first;
    first->next = NULL;

    write(1, "ra\n", 3);
}