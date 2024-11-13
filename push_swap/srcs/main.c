/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:54:08 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/12 14:37:16 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	Count number of numbers given as argument
 */
static int	get_argument_count(int argc, char *argv[])
{
	int	total;

	total = 0;
	while (argc > 1)
	{
		total += get_word_count(argv[argc - 1], ' ');
		argc--;
	}
	return (total);
}

/*	Check if two operations can be condensed into one
 */
static bool	condense_operations(t_stack *stack, int *p, size_t i, bool print)
{
	if (i >= stack->curr_size_op - 1)
		return (false);
	if ((p[i] == SA && p[i + 1] == SB) || (p[i] == SB && p[i + 1] == SA))
	{
		if (print == true)
			ft_putendl_fd("ss", 1);
	}
	else if ((p[i] == RA && p[i + 1] == RB) || (p[i] == RB && p[i + 1] == RA))
	{
		if (print == true)
			ft_putendl_fd("rr", 1);
	}
	else if ((p[i] == RRA && p[i + 1] == RRB)
		|| (p[i] == RRB && p[i + 1] == RRA))
	{
		if (print == true)
			ft_putendl_fd("rrr", 1);
	}
	else if ((p[i] == PA && p[i + 1] == PB) || (p[i] == PB && p[i + 1] == PA)
		|| (p[i] == RA && p[i + 1] == RRA) || (p[i] == RRA && p[i + 1] == RA)
		|| (p[i] == RB && p[i + 1] == RRB) || (p[i] == RRB && p[i + 1] == RB))
		return (true);
	else
		return (false);
	return (true);
}

/*	Print the executed operations, condensing them if possible
 */
void	print_operations(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->curr_size_op)
	{
		if (condense_operations(stack, stack->operations, i, true) == true)
			i++;
		else if (stack->operations[i] == SA)
			ft_putendl_fd("sa", 1);
		else if (stack->operations[i] == SB)
			ft_putendl_fd("sb", 1);
		else if (stack->operations[i] == PA)
			ft_putendl_fd("pa", 1);
		else if (stack->operations[i] == PB)
			ft_putendl_fd("pb", 1);
		else if (stack->operations[i] == RA)
			ft_putendl_fd("ra", 1);
		else if (stack->operations[i] == RB)
			ft_putendl_fd("rb", 1);
		else if (stack->operations[i] == RRA)
			ft_putendl_fd("rra", 1);
		else if (stack->operations[i] == RRB)
			ft_putendl_fd("rrb", 1);
		i++;
	}
}

static size_t	count_operations(t_stack *stack)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < stack->curr_size_op)
	{
		if (condense_operations(stack, stack->operations, i, false) == true)
			i++;
		count++;
		i++;
	}
	return (count);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	int		n_numbers;

	if (argc <= 1)
		error_exit();
	n_numbers = get_argument_count(argc, argv);
	if (n_numbers <= 0)
		error_exit();
	initialize_struct(&stack, n_numbers);
	if (stack == NULL)
		error_exit();
	initialize_arrays(stack, n_numbers, argc, argv);
	my_sort(stack, true);
	if (count_operations(stack) >= 700 && stack->size_a <= 100)
	{
		free_stack(stack);
		initialize_struct(&stack, n_numbers);
		initialize_arrays(stack, n_numbers, argc, argv);
		my_sort(stack, false);
	}
	print_operations(stack);
	free_stack(stack);
	return (0);
}
