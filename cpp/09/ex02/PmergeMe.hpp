/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:06:56 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/15 16:22:07 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_PMERGEME
#define H_PMERGEME

#include <vector>
#include <string>

namespace Ford {
	template <typename Container>
	void	sort(Container &c);

	template <typename Container>
	int		aValue(unsigned int r, unsigned int n);

	template <typename Container>
	int		bValue(unsigned int r, unsigned int n);
}

#endif
