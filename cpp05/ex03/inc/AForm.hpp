/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:57:25 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/02 15:57:25 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _signedStatus;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		AForm(); // default constructor
		virtual ~AForm(); // destructor
		AForm(std::string name, int gradeToSign, int gradeToExecute); // param constructor
		AForm(const AForm& copy); // copy constructor
		AForm& operator=(const AForm& copy); // assignment operator

		const std::string getName() const;
		bool getSignedStatus() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat& b);

		virtual void execute(Bureaucrat const& executor) const = 0;

		void checkForm(Bureaucrat const& executor) const;

	class FormNotSigned : public std::exception {
		public:
			const char *what() const throw();
	};

	class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, const AForm& f);


#endif