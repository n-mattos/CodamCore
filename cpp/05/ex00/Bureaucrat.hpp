/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:40:27 by nmattos-          #+#    #+#             */
/*   Updated: 2026/02/05 11:59:30 by nmattos-         ###   ########.fr       */
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

	class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return ("Grade is too high!");
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return ("Grade is too low!");
        }
    };
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat);

#endif
