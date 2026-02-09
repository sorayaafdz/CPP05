/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:15:00 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/09 13:29:34 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "\nBASIC TEST:\n";
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat worker("Worker", 150);
		Form contract("Contract", 50, 25);

		std::cout << contract << std::endl;

		worker.signForm(contract); // Fail
		boss.signForm(contract); // Success

		std::cout << contract << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
	
	std::cout << "\nEXCEPTION TEST:\n";
	try
	{
		Bureaucrat lowRank("LowRank", 150);
		Form docLow("DocLow", 100, 50);
		lowRank.signForm(docLow);
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	std::cout << "\nEXCEPTION LOW SIGN:\n";
	try
	{
		Form invalidLowSign("InvalidLowSign", 151, 25);
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	std::cout << "\nEXCEPTION HIGH SIGN:\n";
	try
	{
		Form invalidHighSign("InvalidHighSign", 0, 25);
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
	
	std::cout << "\nEXCEPTION LOW EXECUTE:\n";
	try
	{
		Form invalidLowExec("InvalidLowExec", 25, 151);
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
	
	std::cout << "\nEXCEPTION HIGH EXECUTE:\n";
	try
	{
		Form invalidHighExec("InvalidHighExec", 25, 0);
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
	
	std::cout << "\nCOMPLETE TEST:\n";
	try
	{
		Bureaucrat sori("Sori", 1);
		Bureaucrat pikachu("Pikachu", 31);

		std::cout << sori << std::endl;
		std::cout << pikachu << std::endl;

		Form document("Document", 30, 25);
		std::cout << document << std::endl;

		sori.signForm(document); // Success
		pikachu.signForm(document); // Fail
		pikachu.incrementGrade(); // Sign
		std::cout << pikachu << std::endl;
		pikachu.signForm(document); // Success

		std::cout << document << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	return (0);
}
