/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:54:40 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 14:59:34 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	Return the top element of a stack
 */
int	peek(t_stack *stack, char c)
{
	if (c == 'a')
		return (stack->a[stack->size_a - 1]);
	else
		return (stack->b[stack->size_b - 1]);
}

/*	Reallocate memory for an integer array
 */
static int	*int_realloc(int *original, size_t size)
{
	int	*copy;

	copy = malloc((size * 2) * sizeof(int));
	if (copy == NULL)
	{
		free(original);
		return (NULL);
	}
	copy = int_strlcpy(copy, original, size);
	free(original);
	return (copy);
}

/*	Add an operation to the operations array
 *	Allocate additional memory if necessary
 */
void	add_operation(t_stack *stack, int operation, t_stack *s)
{
	if (stack->curr_size_op >= stack->total_size_op)
	{
		stack->operations = int_realloc(stack->operations, stack->curr_size_op);
		if (stack->operations == NULL)
		{
			free(stack->a);
			free(stack->b);
			free(stack);
			if (s != NULL)
				free_stack(s);
			error_exit();
		}
		stack->total_size_op *= 2;
	}
	stack->operations[stack->curr_size_op] = operation;
	stack->curr_size_op++;
}
