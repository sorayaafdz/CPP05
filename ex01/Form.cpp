/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:56:43 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/03 17:11:10 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int sGrade, int eGrade)
	: _name(name), _signed(false), _signGrade(sGrade), _execGrade(eGrade)
{
	if (sGrade < 1 || eGrade < 1)
		throw GradeTooHighException();
	if (sGrade > 150 || eGrade > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
	
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed),
	_signGrade(other._signGrade), _execGrade(other._execGrade)
	  {
		
	  }

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
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

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _signGrade)
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

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName()
	   << " (sign grade " << f.getSignGrade()
	   << ", exec grade " << f.getExecGrade()
	   << "), signed: " << f.isSigned();
	return (os);
}

