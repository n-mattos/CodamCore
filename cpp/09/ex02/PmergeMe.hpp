/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:06:56 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/16 11:38:35 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_PMERGEME
#define H_PMERGEME
#include <algorithm>
#include <iostream>

namespace Ford {
	template <typename Container>
	void	sort(Container &c);

	template <typename Container>
	int		aValue(Container &c, unsigned int r, unsigned int n);

	template <typename Container>
	int		bValue(Container &c, unsigned int r, unsigned int n);
}

#endif
