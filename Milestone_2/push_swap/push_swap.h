#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
}   t_node;

// stack
t_node  *new_node(int value);
void    add_back(t_node **stack, t_node *new);
int     stack_size(t_node *stack);

// operations
void    sa(t_node **a);
void    pb(t_node **a, t_node **b);
void    pa(t_node **a, t_node **b);
void    ra(t_node **a);

// sort
void    sort_three(t_node **a);
int     is_sorted(t_node *a);

#endif