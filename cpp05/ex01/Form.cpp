/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 02:18:06 by ayeap             #+#    #+#             */
/*   Updated: 2025/10/10 02:18:06 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signedStatus(false), _gradeToSign(70), _gradeToExecute(35) {
}

Form::~Form() {
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signedStatus(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& copy) : _name(copy._name), _signedStatus(copy._signedStatus), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
}

Form& Form::operator=(const Form& copy) {
	if (this != &copy) {
		this->_signedStatus = copy._signedStatus;
	}
	return *this;
}

const std::string Form::getName() const {
	return _name;
}

bool Form::getSignedStatus() const {
	return _signedStatus;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() > _gradeToSign) {
		throw Form::GradeTooLowException();
	}
	else {
		_signedStatus = true;
	}
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream &os, const Form& f) {
	os << "Name: " << f.getName() << "\n"
		<< "Signed status: " << f.getSignedStatus() << "\n"
		<< "Grade to Sign: " << f.getGradeToSign() << "\n"
		<< "Grade to Execute: " << f.getGradeToExecute() << std::endl;

	return os;
}