/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:03:02 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/09 17:46:55 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(NULL));

	std::cout << "\nPARSE EXECUTE:\n";
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrubbery("Forest");

		std::cout << boss << std::endl;
		std::cout << shrubbery << std::endl;

		boss.executeForm(shrubbery); // Unsigned
		boss.signForm(shrubbery); // Sign
		boss.executeForm(shrubbery); // Execute

		std::cout << std::endl;
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
		ShrubberyCreationForm shrubbery("Forest");

		std::cout << boss << std::endl;
		std::cout << employee << std::endl;
		std::cout << shrubbery << std::endl;
	
		employee.signForm(shrubbery);
		employee.executeForm(shrubbery); // Insufficient grade
		employee.incrementGrade();
		std::cout << "Increment employee" << std::endl;
		employee.executeForm(shrubbery);

		boss.signForm(shrubbery);
		boss.executeForm(shrubbery);

		std::cout << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception caught: " << exception.what() << std::endl;
	}

	std::cout << "\nROBOTOMYREQUESTFORM:\n";
	try
	{
		Bureaucrat human("Human", 45);
		RobotomyRequestForm robotomy("Robot");

		std::cout << human << std::endl;
		std::cout << robotomy << std::endl;

		human.signForm(robotomy);
		human.executeForm(robotomy);
		human.decrementGrade();
		std::cout << "Decrement Human" << std::endl;
		human.executeForm(robotomy);
		std::cout << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception caught: " << exception.what() << std::endl;
	}

	std::cout << "\nPRESIDENTIALPARDONFORM:\n";
	try
	{
		int i = 0;

		Bureaucrat boss("Boss", 26);
		PresidentialPardonForm pardon("Jack Sparrow");

		std::cout << boss << std::endl;
		std::cout << pardon << std::endl;

		boss.signForm(pardon); // Insufficient grade
		while (i < 22)
		{
			boss.incrementGrade(); // 4
			i++;
		}
		std::cout << "Increment boss 22 times, now: " << boss << std::endl;
		boss.signForm(pardon);
		boss.executeForm(pardon);
		std::cout << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception caught: " << exception.what() << std::endl;
	}

	return (0);
}
