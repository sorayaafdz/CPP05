/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:58:35 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/09 16:16:59 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor" << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
	std::cout << "RobotomyRequestForm parameterized constructor" << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	_target = other._target;
	std::cout << "RobotomyRequestForm copy constructor" << _target << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << "RobotomyRequestForm copy assignment operator" << _target << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor" << _target << std::endl;
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "TRRRRRRRRR" << std::endl;
	if (rand() % 2 == 0)
		std::cout << "RobotomyRequestForm successfully for " << _target << std::endl;
	else
		std::cout << "RobotomyRequestForm failed for " << _target << std::endl;
}
