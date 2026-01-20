/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:49:26 by nmattos-          #+#    #+#             */
/*   Updated: 2026/01/20 13:57:58 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	Bureaucrat Geoffrey("Geoffrey", 39);
	std::cout << Geoffrey << std::endl;
	Geoffrey.incrementGrade();
	std::cout << Geoffrey << std::endl;
	Geoffrey.decrementGrade();
	std::cout << Geoffrey << std::endl;
	return (0);
}
