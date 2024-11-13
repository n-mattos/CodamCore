/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:57:56 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/12 13:53:12 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	Normalize the array of arguments
 */
static int	*normalize(t_stack *stack, int *sorted, int *new)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stack->size_a)
	{
		j = 0;
		while (j < stack->size_a)
		{
			if (sorted[i] == stack->a[j])
			{
				new[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
	return (new);
}

/*	Create the normalized array of arguments
 */
void	normalize_array(t_stack *stack)
{
	int		*sorted;
	int		*new;

	sorted = int_strdup(stack->a, stack->size_a);
	if (sorted == NULL)
	{
		free_stack(stack);
		error_exit();
	}
	new = malloc(stack->size_a * sizeof(int));
	if (new == NULL)
	{
		free_stack(stack);
		free(sorted);
		error_exit();
	}
	quicksort(sorted, 0, stack->size_a - 1);
	new = normalize(stack, sorted, new);
	free(sorted);
	free(stack->a);
	stack->a = new;
}
