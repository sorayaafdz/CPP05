/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:02:38 by sofernan          #+#    #+#             */
/*   Updated: 2026/02/04 14:02:53 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardon", 25, 5), _target(target)
	{
		
	}

void PresidentialPardonForm::executeAction() const
{
	std::cout << _target
	          << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
