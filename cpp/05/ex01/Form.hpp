/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:22:40 by nmattos-          #+#    #+#             */
/*   Updated: 2026/02/05 15:17:12 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_FORM
# define H_FORM

#include "Bureaucrat.hpp"
#include <string>

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_minGradeToSign;
		const int			_minGradeToExecute;

	public:
		Form();
		Form(std::string name, bool isSigned, int minGradeToSign, int minGradetoExecute);
		Form(const Form& other);
		~Form();

		const std::string	getName() const;
		int					getSigned() const;
		int					getMinSignGrade() const;
		int					getMinExecuteGrade() const;
		void				beSigned(const Bureaucrat& Bureaucrat);

	class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return ("Required grade is too high.");
        }
    };

	class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return ("Required grade is too low.");
        }
    };
};

std::ostream& operator<<(std::ostream &out, const Form& form);

#endif
