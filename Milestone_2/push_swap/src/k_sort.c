/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 21:50:00 by alfeofan          #+#    #+#             */
/*   Updated: 2026/05/30 21:54:17 by alfeofan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_position_by_index(t_stack *stack, int target_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

static void	push_to_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = get_chunk_size(size);
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + chunk)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

static void	push_to_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pos;

	while (size > 0)
	{
		pos = get_position_by_index(*stack_b, size - 1);
		if (pos <= size / 2)
		{
			while ((*stack_b)->index != size - 1)
				rb(stack_b);
		}
		else
		{
			while ((*stack_b)->index != size - 1)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		size--;
	}
}

void	k_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	push_to_b(stack_a, stack_b, size);
	push_to_a(stack_a, stack_b, size);
}
