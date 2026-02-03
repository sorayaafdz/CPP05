/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:23:22 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/03 17:25:25 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& n, int s, int e)
	: _name(n), _signed(false), _signGrade(s), _execGrade(e)
{
	if (s < 1 || e < 1)
		throw GradeTooHighException();
	if (s > 150 || e > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
	
}

AForm::AForm(const AForm& o) : _name(o._name), _signed(o._signed),
	_signGrade(o._signGrade), _execGrade(o._execGrade)
	{
		
	}

AForm& AForm::operator=(const AForm& o)
{
	if (this != &o)
		_signed = o._signed;
	return (*this);
}

const std::string& AForm::getName() const
{
	return (_name);
}

bool AForm::isSigned() const
{
	return (_signed);
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExecGrade() const
{
	return (_execGrade);
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(const Bureaucrat& b) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (b.getGrade() > _execGrade)
		throw GradeTooLowException();
	executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}
