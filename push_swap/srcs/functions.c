/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:21:22 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 15:06:01 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

/*	Swap two elements in an array
 */
void	swap(int *arr, int i, int j)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

/*	Duplicate an array of integers
 */
int	*int_strdup(const int *s, size_t len)
{
	int		*dupe;
	size_t	i;

	dupe = malloc((len) * sizeof(int));
	if (dupe == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dupe[i] = s[i];
		i++;
	}
	return (dupe);
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

/*	Copy the contents of one array to another
 */
int	*int_strlcpy(int *dst, int *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
