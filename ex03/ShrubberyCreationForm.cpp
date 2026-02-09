/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:26:33 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/09 17:31:47 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
	std::cout << "ShrubberyCreationForm parameterized constructor " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	_target = other._target;
	std::cout << "ShrubberyCreationForm copy constructor " << _target << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << "ShrubberyCreationForm copy assignment operator " << _target << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor " << _target << std::endl;
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream outfile;
	std::string outFileName;
	
	outFileName = _target + "_shrubbery";
	outfile.open(outFileName.c_str());
	if (!outfile)
	{
		std::cout << "ERROR: couldn't open " << outFileName << std::endl;
		return;
	}
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⢰⣆⠀⢿⢢⡀⠸⣱⡀⢀⢤⡶⡄\n"
		<< "⠀⠀⠀⢰⣤⡴⣴⠢⣧⣿⢤⣈⠺⡧⣺⠷⡟⠓⠃⣇⢧⣶⣀\n"
		<< "⠀⢀⡀⢠⠽⣇⣹⠓⠽⡌⠓⠹⢶⢿⠀⢠⠁⡈⡶⠓⠋⠙⢻⡹⢓⡶\n"
		<< "⠀⣬⣿⡎⠓⠒⠻⢄⡀⢳⡀⠀⢸⠈⢦⢸⠀⣸⢇⠀⢀⣠⡞⢉⣡⣴⣲⠄\n"
		<< "⢠⣽⣈⣇⣴⣲⠖⠀⠉⠚⠳⣄⢸⠀⠈⣿⠊⡼⡦⢏⠉⠀⠉⢙⠮⢱⡆\n"
		<< "⠘⢎⡇⠘⢧⡀⣀⣤⣤⠄⠀⠈⢻⣇⢀⣽⠖⢣⣣⡤⠤⠒⠚⣝⣆\n"
		<< "⠀⠀⠓⠢⠤⠽⢧⣀⠀⠀⠀⠀⠀⣿⠏⢹⡴⠋⠙⠒⠶⢖⢤⡀⢀⣤⣶⠗\n"
		<< "⡢⢄⠐⠮⠷⢆⠀⠈⠙⠛⠛⠻⢶⣿⠀⣾⢀⣀⣀⣤⠤⡼⡓⢋⣿⠫⢕⡆\n"
		<< "⠈⣻⠧⠤⠤⠤⠿⠗⠒⠒⠛⠶⣤⣿⣼⠛⠉⠙⠒⣶⡖⠳⡗⠺⡿⣤⣤⢄⡀\n"
		<< "⠰⣹⠀⠀⠀⢟⡆⠀⠀⠀⠀⠀⠈⣿⡿⠀⠀⠀⠀⢧⠇⠀⠀⠀⠀⠙⠮⡯\n"
		<< "⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⡇\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣇\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⡀\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⡇\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠇\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣄⠀\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣤⠾⠛⣿⠙⠛⠶⢦⠄\n";
	outfile.close();
}
