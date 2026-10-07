/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:38:13 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/05 13:29:59 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>

class Span {
	private:
		unsigned int		_N;
		std::vector<int>	_vector;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void			addMultiple(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void			addNumber(int value);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		unsigned int	getSize();
		int				getValueAtIndex(unsigned int index);

	class no_span : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("No span can be found");
			}
	};

	class out_of_range : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Span is full");
			}
	};

};

std::ostream& operator<<(std::ostream& out, const Span& span);

#endif
