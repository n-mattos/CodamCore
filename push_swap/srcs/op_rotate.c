/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:44:41 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 14:21:19 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	Rotate the stack A
 *	Shift up all elements of stack A by 1
 *	The first element becomes the last
 */
void	ra(t_stack *stack, t_stack *s)
{
	int		last;
	size_t	i;

	if (stack->size_a < 2)
		return ;
	last = peek(stack, 'a');
	i = stack->size_a - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = last;
	add_operation(stack, RA, s);
}

/*	Rotate the stack B
 *	Shift up all elements of stack B by 1
 *	The first element becomes the last
 */
void	rb(t_stack *stack, t_stack *s)
{
	int		last;
	size_t	i;

	if (stack->size_b < 2)
		return ;
	last = peek(stack, 'b');
	i = stack->size_b - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = last;
	add_operation(stack, RB, s);
}
