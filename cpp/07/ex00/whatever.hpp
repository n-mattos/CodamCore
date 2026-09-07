/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 15:24:20 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/07 15:35:50 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_WHATEVER
# define H_WHATEVER

template <typename T> void swap(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

template <typename T> T max(T x, T y) {
	return (x > y) ? x : y;
}

template <typename T> T min(T x, T y) {
	return (x < y) ? x : y;
}

#endif
