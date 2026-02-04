/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:56:22 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/04 16:58:04 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		const int _signGrade;
		const int _execGrade;
		bool _signed;

	public:
		Form();
		Form(const std::string& name, int signGrade, int execGrade);
		Form(const Form &other);
		Form& Form::operator=(const Form& other);
		~Form();

		const std::string& getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public: const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public: const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& output, const Form& form);

#endif
