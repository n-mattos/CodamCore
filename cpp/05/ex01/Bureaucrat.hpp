/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:40:27 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/01 10:45:59 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_BUREAUCRAT
# define H_BUREAUCRAT

#include <string>

class Form;

class Bureaucrat {
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
		void				signForm(Form& form);

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat);

#endif
