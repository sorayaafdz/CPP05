/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:03:02 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/04 14:03:15 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat boss("Boss", 1);
	Bureaucrat worker("Worker", 150);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robo("Bender");
	PresidentialPardonForm pardon("Ford");

	boss.signForm(shrub);
	boss.executeForm(shrub);

	boss.signForm(robo);
	boss.executeForm(robo);

	boss.signForm(pardon);
	boss.executeForm(pardon);

	worker.executeForm(pardon);

	return (0);
}
