/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:57:51 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/03 17:22:54 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;

	public:
		AForm(const std::string& name, int signGrade, int execGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string& getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat& b);
		void execute(const Bureaucrat& executor) const;

		virtual void executeAction() const = 0;

		class GradeTooHighException : public std::exception
		{
		public: const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
		public: const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
		public: const char* what() const throw();
		};
};
