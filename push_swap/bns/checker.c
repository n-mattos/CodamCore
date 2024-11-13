/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:23:56 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/12 14:35:09 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/*	Exit the program with an error message
 */
void	error_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

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

/*	Execute the parsed operation
 */
static void	execute_operation(t_stack *stack, char *operation)
{
	if (ft_strncmp(operation, "sa\n", 3) == 0)
		sa(stack);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		sb(stack);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
		ss(stack);
	else if (ft_strncmp(operation, "pa\n", 3) == 0)
		pa(stack);
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		pb(stack);
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		ra(stack);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		rb(stack);
	else if (ft_strncmp(operation, "rr\n", 3) == 0)
		rr(stack);
	else if (ft_strncmp(operation, "rra\n", 4) == 0)
		rra(stack);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		rrb(stack);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
		rrr(stack);
	else
		error_exit();
}

/*	Parse the operations given by the user (stdin)
 */
static void	parse_operations(t_stack *stack)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation != NULL)
	{
		execute_operation(stack, operation);
		free(operation);
		operation = get_next_line(0);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	int		n_numbers;

	if (argc <= 1)
		error_exit();
	n_numbers = get_argument_count(argc, argv);
	if (n_numbers == 0)
		error_exit();
	initialize_struct(&stack, n_numbers);
	if (stack == NULL)
		error_exit();
	initialize_arrays(stack, n_numbers, argc, argv);
	parse_operations(stack);
	if (is_sorted(stack) && stack->size_b == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack(stack);
	return (0);
}
