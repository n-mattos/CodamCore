/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:38:39 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 14:21:28 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	Swap the top two elements of stack A
 */
void	sa(t_stack *stack, t_stack *s)
{
	if (stack->size_a < 2)
		return ;
	swap(stack->a, stack->size_a - 1, stack->size_a - 2);
	add_operation(stack, SA, s);
}

/*	Swap the top two elements of stack B
 */
void	sb(t_stack *stack, t_stack *s)
{
	if (stack->size_b < 2)
		return ;
	swap(stack->b, stack->size_b - 1, stack->size_b - 2);
	add_operation(stack, SB, s);
}
