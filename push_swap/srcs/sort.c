/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:47:50 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/12 14:04:05 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	Check whether the stack is sorted
 */
static bool	is_sorted(t_stack *stack)
{
	int		turningpoint;
	size_t	i;

	turningpoint = 0;
	i = 0;
	while (i < stack->size_a - 1 && stack->a[i] > stack->a[i + 1])
	{
		if (stack->a[i] < stack->a[i + 1])
			turningpoint++;
		if (turningpoint > 1)
			return (false);
		i++;
	}
	if (i == stack->size_a - 1)
		return (true);
	return (false);
}

/*	Sort the stack if it has 3 numbers
 */
static void	size_three_sort(t_stack *stack)
{
	if (stack->size_a == 1 || stack->size_a > 3)
		return ;
	if (stack->size_a == 2)
	{
		if (stack->a[0] < stack->a[1])
			sa(stack, NULL);
	}
	else if (stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2])
	{
		sa(stack, NULL);
		rra(stack, NULL);
	}
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2])
	{
		rra(stack, NULL);
		if (stack->a[1] < stack->a[2])
			sa(stack, NULL);
	}
	else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2])
	{
		if (stack->a[2] > stack->a[0])
			ra(stack, NULL);
		else
			sa(stack, NULL);
	}
}

/*	Split the stack into three parts:
 *	- The bottom of stack A will contain the largest numbers
 *	- The top of stack B will contain the middle numbers
 *	- The bottom of stack B will contain the smallest numbers
 */
static void	split_stack(t_stack *stack)
{
	int	size;
	int	i;

	size = stack->size_a;
	i = 0;
	while (i++ < size)
	{
		if (peek(stack, 'a') > (size / 3) * 2)
			ra(stack, NULL);
		else if (peek(stack, 'a') < size / 3)
		{
			pb(stack, NULL);
			rb(stack, NULL);
		}
		else
			pb(stack, NULL);
	}
}

static void	small_split_stack(t_stack *stack)
{
	int	size;
	int	i;

	size = stack->size_a;
	i = 0;
	while (i++ < size)
	{
		if (peek(stack, 'a') > (size / 2)
			|| (peek(stack, 'a') == (size / 2) && i < (size / 2)))
			pb(stack, NULL);
		else if (peek(stack, 'a') < size / 2
			|| (peek(stack, 'a') == (size / 2) && i > (size / 2)))
		{
			pb(stack, NULL);
			rb(stack, NULL);
		}
	}
}

/*	Perform the sorting algorithm:
 *	- Split the stack into three parts
 *	- Push from A to B till A has 3 numbers
 *	- Sort the 3 numbers in A
 *	- Push from B to A till B is empty
 */
void	my_sort(t_stack *stack, bool split)
{
	int	key;

	if (is_sorted(stack))
		return ;
	if (stack->size_a > 40 && stack->size_a < 120 && split == true)
		small_split_stack(stack);
	else if (stack->size_a >= 120 && split == true)
		split_stack(stack);
	while (stack->size_a > 3 && is_sorted(stack) == false)
	{
		key = cheapest_operation_a(stack);
		to_top(stack, NULL, key, 'a');
		find_and_insert(stack, NULL, closest_number(stack, key, 'b'), 'b');
	}
	size_three_sort(stack);
	while (stack->size_b > 0)
	{
		key = cheapest_operation_b(stack);
		to_top(stack, NULL, key, 'b');
		find_and_insert(stack, NULL, closest_number(stack, key, 'a'), 'a');
	}
	to_top(stack, NULL, 0, 'a');
}
