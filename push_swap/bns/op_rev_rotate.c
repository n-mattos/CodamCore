/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:46:29 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 16:35:16 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/*	Reverse rotate the stack A
 * 	Shift down all elements of stack A by 1
 * 	The last element becomes the first
 */
void	rra(t_stack *stack)
{
	int		first;
	size_t	i;

	if (stack->size_a < 2)
	{
		free_stack(stack);
		error_exit();
	}
	first = stack->a[0];
	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->size_a - 1] = first;
}

/*	Reverse rotate the stack B
 * 	Shift down all elements of stack B by 1
 * 	The last element becomes the first
 */
void	rrb(t_stack *stack)
{
	int		first;
	size_t	i;

	if (stack->size_b < 2)
	{
		free_stack(stack);
		error_exit();
	}
	first = stack->b[0];
	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->size_b - 1] = first;
}

/*	Reverse rotate both stacks
 */
void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
