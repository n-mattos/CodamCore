/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:40:27 by nmattos-          #+#    #+#             */
/*   Updated: 2026/01/20 13:51:38 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_BUREAUCRAT
# define H_BUREAUCRAT

#include <string>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat);

#endif
