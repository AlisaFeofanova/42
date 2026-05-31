/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:00:00 by alfeofan          #+#    #+#             */
/*   Updated: 2026/05/30 22:09:00 by alfeofan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_min_to_top(t_stack **stack_a)
{
	int	min_val;
	int	pos;
	int	size;

	min_val = find_min(*stack_a);
	pos = get_position(*stack_a, min_val);
	size = stack_size(*stack_a);
	if (pos <= size / 2)
	{
		while ((*stack_a)->value != min_val)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != min_val)
			rra(stack_a);
	}
}

void	sort_three(t_stack **stack_a)
{
	int	max;

	if (is_sorted(*stack_a))
		return ;
	max = find_max(*stack_a);
	if ((*stack_a)->value == max)
		ra(stack_a);
	else if ((*stack_a)->next->value == max)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 5)
	{
		push_min_to_top(stack_a);
		pb(stack_a, stack_b);
	}
	push_min_to_top(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	if (size == 5)
		pa(stack_a, stack_b);
}
