/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:00:14 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/10 14:24:11 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
	std::vector<int> vec = {5, 4, 2, 3, 1};
	int valueToFind = 1;

	typename std::vector<int>::iterator result = easyfind(vec, valueToFind);
	if (result != vec.end()) {
		std::cout << "Found at: [" << std::distance(vec.begin(), result) << "]" << std::endl;
	} else {
		std::cout << "Not found" << std::endl;
	}

	std::list<int> lst = {50, 40, 20, 30, 10};
	valueToFind = 50;

	typename std::list<int>::iterator result2 = easyfind(lst, valueToFind);
	if (result2 != lst.end()) {
		std::cout << "Found at: [" << std::distance(lst.begin(), result2) << "]" << std::endl;
	} else {
		std::cout << "Not found" << std::endl;
	}

	int nonExistentValue = 100;
	typename std::list<int>::iterator result3 = easyfind(lst, nonExistentValue);
	if (result3 != lst.end()) {
		std::cout << "Found at: [" << std::distance(lst.begin(), result3) << "]" << std::endl;
	} else {
		std::cout << "Not found" << std::endl;
	}

	std::deque<int> deq = {50, 40, 30, 20, 10};
	valueToFind = 20;

	typename std::deque<int>::iterator result4 = easyfind(deq, valueToFind);
	if (result4 != deq.end()) {
		std::cout << "Found at: [" << std::distance(deq.begin(), result4) << "]" << std::endl;
	} else {
		std::cout << "Not found" << std::endl;
	}
}
