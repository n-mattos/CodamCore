/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 15:37:19 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/14 14:12:31 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

#ifndef H_ITTER
# define H_ITTER

// Applies a given function to each element of an array
template <typename T> void iter(T *arr, const int length, void (*func)(T&)) {
	std::for_each(arr, arr + length, func);
}

// Overload to allow functions that take const references
template <typename T> void iter(const T *arr, const int length, void (*func)(const T&)) {
	std::for_each(arr, arr + length, func);
}

#endif
