/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:56:22 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/03 17:09:29 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;

	public:
		Form(const std::string& name, int sGrade, int eGrade);
		Form& Form::operator=(const Form& other);
		~Form();

		const std::string& getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception
		{
			public: const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public: const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& f);
