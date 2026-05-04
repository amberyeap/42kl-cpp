/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 21:46:42 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/04 21:46:42 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <map>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string formName, std::string target) {
	std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*createForm[])(std::string) = {
		&Intern::createShrubberyCreation,
		&Intern::createRobotomyRequest,
		&Intern::createPresidentialPardon
	};

	for (int i = 0; i < 3; i++) {
		if (names[i] == formName) {
			std::cout << "Intern creates " << formName <<std::endl;
			return createForm[i](target);
		}
	}

	throw UnknownFormException();
}

AForm* Intern::createShrubberyCreation(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequest(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardon(std::string target) {
	return new PresidentialPardonForm(target);
}


const char* Intern::UnknownFormException::what() const throw() {
	return "Unknown form";
}