/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:02:38 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/09 16:15:37 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor" << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
	std::cout << "PresidentialPardonForm parameterized constructor" << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	_target = other._target;
	std::cout << "PresidentialPardonForm copy constructor" << _target << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << "PresidentialPardonForm copy assignment operator" << _target << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor" << _target << std::endl;
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << "Informs that " << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
