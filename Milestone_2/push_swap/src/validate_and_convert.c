/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_convert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:00:00 by alfeofan          #+#    #+#             */
/*   Updated: 2026/05/30 21:23:51 by alfeofan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_indexes(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*compare;
	int		idx;

	current = stack_a;
	while (current)
	{
		idx = 0;
		compare = stack_a;
		while (compare)
		{
			if (compare->value < current->value)
				idx++;
			compare = compare->next;
		}
		current->index = idx;
		current = current->next;
	}
}

int	ft_atoi(const char *str, t_stack **stack_a, char **matrix)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		print_error_clean(stack_a, matrix);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			print_error_clean(stack_a, matrix);
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num) < INT_MIN))
			print_error_clean(stack_a, matrix);
		i++;
	}
	return ((int)(num * sign));
}

void	stack_add_back(t_stack **stack, int num)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = num;
	new_node->index = -1;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_node;
}
