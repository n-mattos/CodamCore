/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:22:40 by nmattos-          #+#    #+#             */
/*   Updated: 2026/02/05 12:59:34 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_BUREAUCRAT
# define H_BUREAUCRAT

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
