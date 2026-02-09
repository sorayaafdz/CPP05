/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:55:03 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/05 17:25:18 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "TEST 1: NORMAL CASE" << std::endl;
	try
	{
		Bureaucrat a("Sori", 2);
		std::cout << a << std::endl;

		a.incrementGrade(); // 2 to 1
		std::cout << a << std::endl;

		a.decrementGrade(); // 1 to 2
		std::cout << a << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	std::cout << "\nTEST 2: GRADE TOO HIGH" << std::endl;
	try
	{
		Bureaucrat b("Bob", 1);
		std::cout << b << std::endl;
		b.incrementGrade(); // Exception
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	std::cout << "\nTEST 3: GRADE TOO LOW" << std::endl;
	try
	{
		Bureaucrat c("Charlie", 150);
		std::cout << c << std::endl;
		c.decrementGrade(); // Exception
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	std::cout << "\nTEST 4: INVALID CONSTRUCTION" << std::endl;
	try
	{
		Bureaucrat d("Invalid", 151); // Exception in the constructor
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	return (0);
}
