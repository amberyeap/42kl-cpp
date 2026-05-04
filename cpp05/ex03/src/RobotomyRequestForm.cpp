/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:21:12 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/04 15:21:12 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other) {
	if (this != &other)
		this->_target = other._target;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	checkForm(executor);

	std::cout << "*** DRILLING NOISES ***" << std::endl;
	int randomNum = rand() % 2;
	if (randomNum == 1)
		std::cout << _target << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy has failed." << std::endl;
}