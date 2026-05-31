/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:00:00 by alfeofan          #+#    #+#             */
/*   Updated: 2026/05/30 21:55:37 by alfeofan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int					value;
	int					index;
	struct s_stack		*next;
}	t_stack;

// operations
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// validate_and_convert.c
void	set_indexes(t_stack *stack_a);
int		ft_atoi(const char *str, t_stack **stack_a, char **matrix);
void	stack_add_back(t_stack **stack, int num);

// utils.c
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
int		get_position(t_stack *stack, int target_value);

// ft_split.c
char	**ft_split(char const *s, char c);

// simple_sort.c
void	sort_three(t_stack **stack);
void	sort_five(t_stack **stack_a, t_stack **stack_b);

// k_sort.c
int		get_position_by_index(t_stack *stack, int target_index);
void	k_sort(t_stack **stack_a, t_stack **stack_b);

// check_error.c
int		check_duplicates(t_stack *stack, int num);
void	print_error_clean(t_stack **stack_a, char **matrix);
void	print_error(t_stack **stack);
void	free_matrix(char **strs);
void	free_stack(t_stack **stack);

#endif