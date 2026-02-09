/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:59:30 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/09 17:39:22 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

typedef AForm* (*CreateFn)(const std::string &);

Intern::Intern()
{
	std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern copy constructor" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "Intern copy assignment operator" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor " << std::endl;
}

AForm* createShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* createRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* createPresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	const std::string names[3] =
	{
		"shrubbery creation form",
		"robotomy request form",
		"presidential pardon form"
	};

	AForm* (*creators[3])(const std::string&) =
	{
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (creators[i](target));
		}
	}
	std::cout << "Intern cannot create " << formName << std::endl;
	return (NULL);
}

