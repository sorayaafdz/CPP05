/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:17:28 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/09 17:26:22 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctime"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	std::srand(std::time(NULL));

	std::cout << "\nPARSE:\n";
	try
	{
		Bureaucrat boss("Boss", 1);
		Intern intern;
		AForm *shrubberyFormIntern;
		
		shrubberyFormIntern = intern.makeForm("shrubbery creation", "Forest");
		if (!shrubberyFormIntern)
			throw std::runtime_error("That form not exist");
		std::cout << boss << std::endl;
		std::cout << *shrubberyFormIntern << std::endl;
		
		std::cout << std::endl;
		delete shrubberyFormIntern;
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception caught: " << exception.what() << std::endl;
	}

	std::cout << "\nSHRUBBERYCREATIONFORM:\n";
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat employee("Employee", 138);
		Intern intern;
		AForm *shrubberyFormIntern;

		shrubberyFormIntern = intern.makeForm("shrubbery creation form", "Forest");
		if (!shrubberyFormIntern)
			throw std::runtime_error("That form not exist");
		std::cout << boss << std::endl;
		std::cout << employee << std::endl;
		std::cout << *shrubberyFormIntern << std::endl;

		employee.signForm(*shrubberyFormIntern);
		employee.executeForm(*shrubberyFormIntern);
		employee.incrementGrade();
		std::cout << "Increment employee" << std::endl;
		employee.executeForm(*shrubberyFormIntern);

		boss.signForm(*shrubberyFormIntern);
		boss.executeForm(*shrubberyFormIntern);

		std::cout << std::endl;
		delete shrubberyFormIntern;
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception caught: " << exception.what() << std::endl;
	}

	std::cout << "\nROBOTOMYREQUESTFORM:\n";
	try
	{
		Bureaucrat human("Human", 45);
		Intern intern;
		AForm *robotomyFormIntern;

		robotomyFormIntern = intern.makeForm("robotomy request form", "Robot");
		if (!robotomyFormIntern)
			throw std::runtime_error("That form not exist");

		std::cout << human << std::endl;
		std::cout << *robotomyFormIntern << std::endl;

		human.signForm(*robotomyFormIntern);
		human.executeForm(*robotomyFormIntern);
		human.executeForm(*robotomyFormIntern);
		human.decrementGrade();
		std::cout << "Decrement Human" << std::endl;
		human.executeForm(*robotomyFormIntern);

		std::cout << std::endl;
		delete robotomyFormIntern;
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception caught: " << exception.what() << std::endl;
	}

	std::cout << "\nPRESIDENTIALPARDONFORM:\n";
	try
	{
		Bureaucrat boss("Boss", 4);
		Intern intern;
		AForm *pardonFormIntern;

		pardonFormIntern = intern.makeForm("presidential pardon form", "Jack Sparrow");
		if (!pardonFormIntern)
			throw std::runtime_error("That form not exist");

		std::cout << boss << std::endl;
		std::cout << *pardonFormIntern << std::endl;

		boss.signForm(*pardonFormIntern);
		boss.executeForm(*pardonFormIntern);

		std::cout << std::endl;
		delete pardonFormIntern;
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception caught: " << exception.what() << std::endl;
	}

	return (0);
}