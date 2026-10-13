/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:41:47 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/13 13:07:49 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_RPN
#define H_RPN

#include <string>
#include <stack>

class RPN {
	private:
		RPN() = delete;
		RPN(const RPN& other) = delete;
		RPN& operator=(const RPN& other) = delete;
		~RPN() = delete;

		static float _performOperation(std::stack<float> *stack, std::string mathOperator);

	public:
		static float calculate(const std::string &input);
};

#endif
