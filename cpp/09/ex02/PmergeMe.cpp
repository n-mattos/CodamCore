/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:06:58 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/16 11:29:37 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Use Ford-Johnson's sorting algorithm
template <typename Container>
void Ford::sort(Container &c) {
	(void)c;
}

// pairSize = size of each pair in current depth
// n = 'nth' element to access: a1, a2, a..., an
template <typename Container>
int	Ford::aValue(Container &c, unsigned int pairSize, unsigned int n) {
	if (n == 0 || pairSize == 0)
		throw std::out_of_range("index must be greater than zero");
	return(c.at(n * (pairSize) - 1));
}

// pairSize = size of each pair in current depth
// n = 'nth' element to access: b1, b2, b..., bn
template <typename Container>
int	Ford::bValue(Container &c, unsigned int pairSize, unsigned int n) {
	if (n == 0 || pairSize == 0)
		throw std::out_of_range("index must be greater than zero");
	return(c.at((n * (pairSize) - 1) - (pairSize / 2)));
}
