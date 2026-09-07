/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:29:52 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/07 11:52:13 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
	Data data;
	data.value = 42;

	std::cout << "Original: " << data.value << std::endl;

	// Serialize on address of 'data'
	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized: " << serialized << std::endl;

	// Pass return value ('serialized') back to deserialize
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized: " << deserialized->value << std::endl;

	return 0;
}
