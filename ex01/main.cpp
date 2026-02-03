/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:15:00 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/03 17:15:18 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat boss("Boss", 1);
	Bureaucrat worker("Worker", 150);

	Form contract("Contract", 50, 25);

	std::cout << contract << std::endl;

	worker.signForm(contract);
	boss.signForm(contract);

	std::cout << contract << std::endl;

	return (0);
}
