/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:32:39 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/10 14:23:32 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_FIND
# define H_FIND

// Return iterator to the first occurrence of x in container, or container.end() if not found.
template <typename T> typename T::iterator easyfind(T& container, int x) {
	for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
		if (*it == x)
			return (it);
	}

	// Not finding the key is expected, so container.end() makes sense.
	// If it's highly unexpected for the value not to be found, an exception would fit.
	return (container.end());
}

#endif
