/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:50:31 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 16:35:09 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/*	Push the top element of stack B to stack A
 */
void	pa(t_stack *stack)
{
	if (stack->size_b == 0)
	{
		free_stack(stack);
		error_exit();
	}
	stack->a[stack->size_a] = peek(stack, 'b');
	stack->size_a++;
	stack->size_b--;
}

/*	Push the top element of stack A to stack B
 */
void	pb(t_stack *stack)
{
	if (stack->size_a == 0)
	{
		free_stack(stack);
		error_exit();
	}
	stack->b[stack->size_b] = peek(stack, 'a');
	stack->size_b++;
	stack->size_a--;
}
