/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:54:20 by nmattos-          #+#    #+#             */
/*   Updated: 2024/10/29 15:16:08 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_realloc(char **original, size_t size)
{
	char	*copy;

	copy = malloc(size * sizeof(char));
	if (copy == NULL)
	{
		free_p(original);
		return (NULL);
	}
	copy = ft_strcpy(copy, *original);
	free_p(original);
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	c %= 256;
	while (*s != c)
	{
		if (*s == '\0')
		{
			if (c == 0)
				return ((char *)s);
			else
				return (NULL);
		}
		s++;
	}
	return ((char *)s);
}

void	free_p(char **p)
{
	free(*p);
	*p = NULL;
}
