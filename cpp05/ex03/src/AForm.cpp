/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 02:18:06 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/04 19:08:30 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signedStatus(false), _gradeToSign(70), _gradeToExecute(35) {
}

AForm::~AForm() {
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signedStatus(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signedStatus(copy._signedStatus), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
}

AForm& AForm::operator=(const AForm& copy) {
	if (this != &copy) {
		this->_signedStatus = copy._signedStatus;
	}
	return *this;
}

const std::string AForm::getName() const {
	return _name;
}

bool AForm::getSignedStatus() const {
	return _signedStatus;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat& b) {
	if (b.getGrade() > _gradeToSign) {
		throw AForm::GradeTooLowException();
	}
	else {
		_signedStatus = true;
	}
}

void AForm::checkForm(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw GradeTooLowException();
	}
	if (getSignedStatus() == false)
		throw AForm::FormNotSigned();
}

const char* AForm::FormNotSigned::what() const throw() {
	return "Form is not signed";
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream &os, const AForm& f) {
	os << "Name: " << f.getName() << "\n"
		<< "Signed status: " << f.getSignedStatus() << "\n"
		<< "Grade to Sign: " << f.getGradeToSign() << "\n"
		<< "Grade to Execute: " << f.getGradeToExecute() << std::endl;

	return os;
}