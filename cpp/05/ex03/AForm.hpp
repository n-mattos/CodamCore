/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:35:13 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/02 11:52:08 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_AFORM
# define H_AFORM

#include <string>

class Bureaucrat;

// Abstract due to pure virtual function 'execute'
class AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_minGradeToSign;
		const int			_minGradeToExecute;

	public:
		AForm();
		AForm(std::string name, bool isSigned, int minGradeToSign, int minGradetoExecute);
		AForm(const AForm& other);
		virtual ~AForm();

		const std::string	getName() const;
		int					getSigned() const;
		int					getMinSignGrade() const;
		int					getMinExecuteGrade() const;
		// 'Regular' virtual to allow overrides whilst having a default
		virtual void		beSigned(const Bureaucrat& Bureaucrat);
		// Pure virtual to force an implementation by derived classes
		virtual void		execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
    };

	class NotSignedException : public std::exception {
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const AForm& form);

#endif
