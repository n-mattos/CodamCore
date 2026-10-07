/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:32:39 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/07 13:09:50 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_FIND
# define H_FIND

#include <algorithm>

// Return iterator to the first occurrence of x in container, or container.end() if not found.
template <typename T> typename T::iterator easyfind(T& container, int x) {
	typename T::iterator found = std::find(container.begin(), container.end(), x);
	return (found);
}

#endif
