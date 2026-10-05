/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:38:13 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/10 14:49:34 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span {
	private:
		unsigned int		_N;
		std::vector<int>	_vector;

	public:
		Span(unsigned int N);
		~Span();

		void			addNumber(int value);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};

#endif
