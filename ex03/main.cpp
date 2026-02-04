/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:17:28 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/04 14:17:51 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Intern intern;
	Bureaucrat boss("Boss", 1);

	AForm* f1 = intern.makeForm("robotomy request", "Bender");
	if (f1)
	{
		boss.signForm(*f1);
		boss.executeForm(*f1);
		delete (f1);
	}

	AForm* f2 = intern.makeForm("shrubbery creation", "Home");
	if (f2)
	{
		boss.signForm(*f2);
		boss.executeForm(*f2);
		delete (f2);
	}

	AForm* f3 = intern.makeForm("unknown form", "Nobody");
	if (f3)
		delete (f3);

	return (0);
}
