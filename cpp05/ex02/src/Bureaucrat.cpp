/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:16:13 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/04 21:05:05 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	// std::cout << "Bureaucrat " << _name << " with grade " << _grade << " ready!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	// std::cout << "Bureaucrat " << _name << " with grade " << _grade << " ready!" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bye bye, bureaucrat " << _name << std::endl;

}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
	if (this != &copy) {
		this->_grade = copy._grade;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
	
	// std::cout << "Bureaucrat " << _name << "'s new grade is " << _grade << std::endl;
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;

	// std::cout << "Bureaucrat " << _name << "'s new grade is " << _grade << std::endl;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}


void Bureaucrat::executeForm(AForm const& form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " failed to execute " << form << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}