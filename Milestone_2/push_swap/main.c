#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_node *a = NULL;
    t_node *b = NULL;
    int i = 1;

    while (i < argc)
    {
        add_back(&a, new_node(atoi(argv[i])));
        i++;
    }

    if (!is_sorted(a) && stack_size(a) == 3)
        sort_three(&a);

    return (0);
}