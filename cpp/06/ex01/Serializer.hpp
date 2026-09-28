/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/07 11:21:54 by nmattos-      #+#    #+#                 */
/*   Updated: 2026/09/28 11:44:33 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_SERIALIZER
# define H_SERIALIZER

#include <stdint.h>

// non-empty Data structure
struct Data {
	int value;
};

class Serializer {
	private:
		Serializer() = delete;
		Serializer(const Serializer& other) = delete;
		Serializer& operator=(const Serializer& other) = delete;
		~Serializer() = delete;

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
