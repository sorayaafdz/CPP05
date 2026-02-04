/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:56:43 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/04 17:08:16 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name(), _signGrade(50), _execGrade(50)
{
	_signed = false;
	std::cout << "Form default constructor" << std::endl;
}

Form::Form(const std::string& name, int signGrade, int execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form parameterized constructor" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed),
	_signGrade(other._signGrade), _execGrade(other._execGrade)
	  {
		std::cout << "Form copy constructor" << std::endl;
	  }

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_signed = other._signed;
	std::cout << "Form copy assignment operator" << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}

const std::string& Form::getName() const
{
	return (_name);
}

bool Form::isSigned() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecGrade() const
{
	return (_execGrade);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}

std::ostream& operator<<(std::ostream& output, const Form& form)
{
	output << form.getName()
	   << " (sign grade " << form.getSignGrade()
	   << ", exec grade " << form.getExecGrade()
	   << "), signed: " << form.isSigned();
	return (output);
}

