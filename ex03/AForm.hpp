/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:57:51 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/09 13:37:21 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

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
		AForm();
		AForm(const std::string& name, int signGrade, int execGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string& getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool isSigned() const;
		void beSigned(const Bureaucrat& bureaucrat);
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

std::ostream &operator<<(std::ostream &output, const AForm &aform);

#endif
