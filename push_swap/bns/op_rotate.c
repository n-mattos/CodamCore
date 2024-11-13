/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:44:41 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 16:35:23 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/*	Rotate the stack A
 *	Shift up all elements of stack A by 1
 *	The first element becomes the last
 */
void	ra(t_stack *stack)
{
	int		last;
	size_t	i;

	if (stack->size_a < 2)
	{
		free_stack(stack);
		error_exit();
	}
	last = peek(stack, 'a');
	i = stack->size_a - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = last;
}

/*	Rotate the stack B
 *	Shift up all elements of stack B by 1
 *	The first element becomes the last
 */
void	rb(t_stack *stack)
{
	int		last;
	size_t	i;

	if (stack->size_b < 2)
	{
		free_stack(stack);
		error_exit();
	}
	last = peek(stack, 'b');
	i = stack->size_b - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = last;
}

/*	Rotate both stacks
 */
void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
