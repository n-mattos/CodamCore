/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 15:37:19 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/07 15:50:47 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_ITTER
# define H_ITTER

template <typename T> void iter(T *arr, const int length, void (*func)(T&)) {
	for (int i = 0; i < length; i++)
		func(arr[i]);
}

#endif
