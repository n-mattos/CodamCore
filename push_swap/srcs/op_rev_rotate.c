/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:46:29 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 14:21:11 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	Reverse rotate the stack A
 * 	Shift down all elements of stack A by 1
 * 	The last element becomes the first
 */
void	rra(t_stack *stack, t_stack *s)
{
	int		first;
	size_t	i;

	if (stack->size_a < 2)
		return ;
	first = stack->a[0];
	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->size_a - 1] = first;
	add_operation(stack, RRA, s);
}

/*	Reverse rotate the stack B
 * 	Shift down all elements of stack B by 1
 * 	The last element becomes the first
 */
void	rrb(t_stack *stack, t_stack *s)
{
	int		first;
	size_t	i;

	if (stack->size_b < 2)
		return ;
	first = stack->b[0];
	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->size_b - 1] = first;
	add_operation(stack, RRB, s);
}
