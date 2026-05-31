/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:00:00 by alfeofan          #+#    #+#             */
/*   Updated: 2026/05/30 21:49:56 by alfeofan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_empty_arg(const char *arg, t_stack **stack_a)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	if (arg[i] == '\0')
		print_error(stack_a);
	while (arg[i])
	{
		if ((arg[i] >= '0' && arg[i] <= '9'))
			has_digit = 1;
		i++;
	}
	if (!has_digit)
		print_error(stack_a);
}

static void	start_sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		k_sort(stack_a, stack_b);
}

static void	parse_arguments(char *argv_i, t_stack **stack_a)
{
	char	**args;
	int		j;
	int		num;

	check_empty_arg(argv_i, stack_a);
	args = ft_split(argv_i, ' ');
	if (!args)
		print_error_clean(stack_a, NULL);
	j = 0;
	if (!args[j])
		print_error_clean(stack_a, args);
	while (args[j])
	{
		num = ft_atoi(args[j], stack_a, args);
		if (check_duplicates(*stack_a, num))
			print_error_clean(stack_a, args);
		stack_add_back(stack_a, num);
		j++;
	}
	free_matrix(args);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		parse_arguments(argv[i], &stack_a);
		i++;
	}
	set_indexes(stack_a);
	if (!is_sorted(stack_a))
		start_sorting(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
