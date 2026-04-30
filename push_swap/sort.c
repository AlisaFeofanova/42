#include "push_swap.h"

int is_sorted(t_node *a)
{
    while (a && a->next)
    {
        if (a->value > a->next->value)
            return (0);
        a = a->next;
    }
    return (1);
}

void sort_three(t_node **a)
{
    int x = (*a)->value;
    int y = (*a)->next->value;
    int z = (*a)->next->next->value;

    if (x > y && y < z && x < z)
        sa(a);
    else if (x > y && y > z)
    {
        sa(a);
        ra(a);
    }
    else if (x > y && y < z && x > z)
        ra(a);
    else if (x < y && y > z && x < z)
    {
        sa(a);
        ra(a);
    }
    else if (x < y && y > z && x > z)
        ra(a);
}