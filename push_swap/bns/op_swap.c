/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:38:39 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 16:35:36 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/*	Swap the top two elements of stack A
 */
void	sa(t_stack *stack)
{
	if (stack->size_a < 2)
	{
		free_stack(stack);
		error_exit();
	}
	swap(stack->a, stack->size_a - 1, stack->size_a - 2);
}

/*	Swap the top two elements of stack B
 */
void	sb(t_stack *stack)
{
	if (stack->size_b < 2)
	{
		free_stack(stack);
		error_exit();
	}
	swap(stack->b, stack->size_b - 1, stack->size_b - 2);
}

/*	Swap the top two elements of both stacks
 */
void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}
