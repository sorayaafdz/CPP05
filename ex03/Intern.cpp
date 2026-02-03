/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:59:30 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/03 17:00:16 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	const std::string names[3] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*creators[3])(const std::string&) =
	{
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return creators[i](target);
		}
	}

	std::cout << "Intern cannot create " << name << std::endl;
	return (NULL);
}
