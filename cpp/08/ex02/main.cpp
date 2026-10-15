/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:36:34 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/15 10:59:08 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << '\n';

	mstack.pop();

	std::cout << "Size: " << mstack.size() << '\n';

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "\nIterating through MutantStack using iterators" << '\n';
	while (it != ite) {
		std::cout << *it << ' ';
		++it;
	}
	std::cout << '\n';

	// Copying the MutantStack to a std::stack
	std::cout << "\nCopying MutantStack to std::stack" << '\n';
	std::stack<int> s(mstack);
	std::cout << "Copied stack (full): Size: " << s.size() << '\n';
	while (!s.empty()) {
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << '\n';

	// Same code but with list for comparison
	std::cout << "\nUsing std::list for comparison" << '\n';
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Back: " << lst.back() << '\n';

	lst.pop_back();

	std::cout << "Size: " << lst.size() << '\n';

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it_lst = lst.begin();
	std::list<int>::iterator ite_lst = lst.end();

	++it_lst;
	--it_lst;
	std::cout << "\nIterating through std::list using iterators" << '\n';
	while (it_lst != ite_lst) {
		std::cout << *it_lst << '\n';
		++it_lst;
	}

	return (0);
}