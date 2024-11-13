/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:36:51 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 15:36:28 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/*	Initialize the stack struct
 */
void	initialize_struct(t_stack **stack, int n_numbers)
{
	*stack = malloc(sizeof(t_stack));
	if (*stack == NULL)
		error_exit();
	(*stack)->a = malloc(sizeof(int) * (n_numbers));
	if ((*stack)->a == NULL)
		return (free(*stack));
	(*stack)->size_a = n_numbers;
	(*stack)->b = ft_calloc(sizeof(int), (n_numbers));
	if ((*stack)->b == NULL)
	{
		free((*stack)->a);
		free(*stack);
		error_exit();
	}
	(*stack)->size_b = 0;
}

/*	Free the stack and its arrays
 */
void	free_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
}

/*	Free a double array
 */
void	free_double_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
