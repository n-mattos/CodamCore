/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:32:50 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 15:34:55 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/*	Check if an array contains duplicates
 */
static bool	contains_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

/*	Get the number of numbers in a string
 */
static char	**get_number_list(t_stack *stack, char *str)
{
	char	**number_list;

	number_list = ft_split(str, ' ');
	if (number_list == NULL)
	{
		free_stack(stack);
		error_exit();
	}
	return (number_list);
}

/*	Fill the array with the arguments
 */
static void	fill_array(t_stack *stack, char *str, int *k)
{
	char	**number_list;
	int		value;
	int		j;
	int		error;

	number_list = get_number_list(stack, str);
	j = get_word_count(str, ' ') - 1;
	while (j >= 0)
	{
		if (is_number(number_list[j]) == false)
		{
			free_stack(stack);
			free_double_array(number_list);
			error_exit();
		}
		value = ft_atoi(number_list[j--], &error);
		if (error == 1)
		{
			free_stack(stack);
			free_double_array(number_list);
			error_exit();
		}
		stack->a[(*k)++] = value;
	}
	free_double_array(number_list);
}

/*	Initialize and fill the arrays of the stack struct
 */
void	initialize_arrays(t_stack *stack, int n_numbers, int argc, char **argv)
{
	int		i;
	int		k;

	i = argc;
	k = 0;
	while (i-- > 1)
		fill_array(stack, argv[i], &k);
	if (contains_duplicates(stack->a, n_numbers))
	{
		free_stack(stack);
		error_exit();
	}
}
