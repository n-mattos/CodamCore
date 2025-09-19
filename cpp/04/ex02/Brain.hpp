/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:48:40 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/19 12:54:33 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_BRAIN
# define H_BRAIN

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		~Brain();
};

#endif
