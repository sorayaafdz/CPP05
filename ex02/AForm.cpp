/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:23:22 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/04 15:30:42 by sofernan         ###   ########.fr       */
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

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed),
	_signGrade(other._signGrade), _execGrade(other._execGrade)
	{
		
	}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_signed = other._signed;
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

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(const Bureaucrat& bureaucrat) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (bureaucrat.getGrade() > _execGrade)
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
