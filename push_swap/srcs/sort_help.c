/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:41:17 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 15:05:19 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	Find the index of the given key
 */
static size_t	find_key_index(t_stack *stack, int key, char c)
{
	size_t	key_index;

	key_index = 0;
	if (c == 'a')
	{
		while (stack->a[key_index] != key)
			key_index++;
	}
	else
	{
		while (stack->b[key_index] != key)
			key_index++;
	}
	return (key_index);
}

/*	Rotate the given key to the top of the stack
 */
void	to_top(t_stack *stack, t_stack *s, int key, char c)
{
	if (c == 'a')
	{
		if (stack->size_a < 2)
			return ;
		if (find_key_index(stack, key, 'a') >= stack->size_a / 2)
			while (key != peek(stack, 'a'))
				ra(stack, s);
		else
			while (key != peek(stack, 'a'))
				rra(stack, s);
	}
	else
	{
		if (stack->size_b < 2)
			return ;
		if (find_key_index(stack, key, 'b') >= stack->size_b / 2)
			while (key != peek(stack, 'b'))
				rb(stack, s);
		else
			while (key != peek(stack, 'b'))
				rrb(stack, s);
	}
}

/*	Find the number (key) in the stack and insert it in the correct position
 */
void	find_and_insert(t_stack *stack, t_stack *s, int key, char c)
{
	if (c == 'a')
	{
		to_top(stack, s, key, 'a');
		if (peek(stack, 'b') > key)
			ra(stack, s);
		pa(stack, s);
	}
	else
	{
		to_top(stack, s, key, 'b');
		if (peek(stack, 'a') < key)
			rb(stack, s);
		pb(stack, s);
	}
}

/*	Find the closest number to x in the stack
 */
int	closest_number(t_stack *stack, int x, char c)
{
	size_t	i;
	int		closest;

	i = 0;
	if (c == 'a')
	{
		closest = stack->a[0];
		while (i < stack->size_a)
		{
			if (abs((stack->a[i] - x)) < abs((closest - x)))
				closest = stack->a[i];
			i++;
		}
	}
	else
	{
		closest = stack->b[0];
		while (i < stack->size_b)
		{
			if (abs((stack->b[i] - x)) < abs((closest - x)))
				closest = stack->b[i];
			i++;
		}
	}
	return (closest);
}
