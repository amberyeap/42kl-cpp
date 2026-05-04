/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:20:59 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/04 21:01:32 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
		this->_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	checkForm(executor);

	std::ofstream file((_target + ".txt").c_str());
	file << "   .vVv.Vv." << std::endl;
	file << "  vVvVvVvVv" << std::endl;
	file << "  VvVvVvVvV" << std::endl;
	file << "   'VvVvV'" << std::endl;
	file << "     |||" << std::endl;
	file << "     |||" << std::endl;
}
