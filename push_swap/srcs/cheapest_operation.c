/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:38:34 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/12 10:13:09 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	Allocate memory for the copy stack's arrays
 */
static void	allocate_copy_arrays(t_stack **copy, t_stack *stack)
{
	(*copy)->a = ft_calloc(sizeof(int), stack->size_a + stack->size_b);
	if ((*copy)->a == NULL)
	{
		free_stack(stack);
		free(*copy);
		error_exit();
	}
	(*copy)->b = ft_calloc(sizeof(int), stack->size_a + stack->size_b);
	if ((*copy)->b == NULL)
	{
		free_stack(stack);
		free((*copy)->a);
		free(*copy);
		error_exit();
	}
	(*copy)->operations = malloc(250 * sizeof(int));
	if ((*copy)->operations == NULL)
	{
		free_stack(stack);
		free((*copy)->a);
		free((*copy)->b);
		free(*copy);
		error_exit();
	}
}

/*	Make a 1 to 1 copy of the stack, excluding the operations array
 */
static void	copy_stack(t_stack **copy, t_stack *stack)
{
	*copy = malloc(sizeof(t_stack));
	if (copy == NULL)
	{
		free_stack(stack);
		error_exit();
	}
	allocate_copy_arrays(copy, stack);
	(*copy)->size_a = stack->size_a;
	(*copy)->size_b = stack->size_b;
	(*copy)->curr_size_op = 0;
	(*copy)->total_size_op = 250;
	int_strlcpy((*copy)->a, stack->a, stack->size_a);
	int_strlcpy((*copy)->b, stack->b, stack->size_b);
}

/*	Find the cheapest number to push from A to B
 */
int	cheapest_operation_a(t_stack *stack)
{
	t_stack	*copy;
	size_t	cheapest_key;
	size_t	cost_cheapest_key;
	int		key;
	size_t	i;

	i = 0;
	cheapest_key = 0;
	cost_cheapest_key = SIZE_MAX;
	while (i < stack->size_a)
	{
		copy_stack(&copy, stack);
		key = stack->a[i];
		to_top(copy, stack, key, 'a');
		find_and_insert(copy, stack, closest_number(copy, key, 'b'), 'b');
		if (copy->curr_size_op < cost_cheapest_key)
		{
			cheapest_key = key;
			cost_cheapest_key = copy->curr_size_op;
		}
		i++;
		free_stack(copy);
	}
	return (cheapest_key);
}

/*	Find the cheapest number to push from B to A
 */
int	cheapest_operation_b(t_stack *stack)
{
	t_stack	*copy;
	size_t	cheapest_key;
	size_t	cost_cheapest_key;
	int		key;
	size_t	i;

	i = 0;
	cheapest_key = 0;
	cost_cheapest_key = SIZE_MAX;
	while (i < stack->size_b)
	{
		copy_stack(&copy, stack);
		key = stack->b[i];
		to_top(copy, stack, key, 'b');
		find_and_insert(copy, stack, closest_number(copy, key, 'a'), 'a');
		if (copy->curr_size_op < cost_cheapest_key)
		{
			cheapest_key = key;
			cost_cheapest_key = copy->curr_size_op;
		}
		i++;
		free_stack(copy);
	}
	return (cheapest_key);
}
