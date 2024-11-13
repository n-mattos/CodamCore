/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:29:33 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 16:12:27 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/*	Count the number of words in a string
 */
int	get_word_count(char *s, char c)
{
	int	word_count;
	int	length_str;

	length_str = ft_strlen(s);
	word_count = 0;
	if (*s == '\0')
		return (0);
	if (c == 0)
		return (1);
	while (*s == c)
		s++;
	while (*s != '\0')
	{
		if (*s == c)
		{
			word_count++;
			while (*s == c)
				s++;
		}
		else
			s++;
	}
	if (*(s - 1) != c)
		word_count++;
	return (word_count);
}

/*	Check if a string is a number
 */
bool	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

/*	Return the top element of a stack
 */
int	peek(t_stack *stack, char c)
{
	if (c == 'a')
		return (stack->a[stack->size_a - 1]);
	else
		return (stack->b[stack->size_b - 1]);
}

/*	Swap two elements in an array
 */
void	swap(int *arr, int i, int j)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

bool	is_sorted(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] < stack->a[i + 1])
			return (false);
		i++;
	}
	return (true);
}
