/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:53:19 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/02 11:02:54 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_INTERN
# define H_INTERN

#include <string>

class AForm;

class Intern {
	public:
		Intern();
		~Intern();

		AForm*	makeForm(std::string name, std::string target);
};

#endif
