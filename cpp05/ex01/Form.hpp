/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 02:18:14 by ayeap             #+#    #+#             */
/*   Updated: 2025/10/10 02:18:14 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
// #include "Bureaucrat.hpp"

class Bureaucrat; // forward declarations to avoid circular inclusions

class Form {
	private:
		const std::string _name;
		bool _signedStatus;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		Form(); // default constructor
		~Form(); // destructor
		Form(std::string name, int gradeToSign, int gradeToExecute); // param constructor
		Form(const Form& copy); // copy constructor
		Form& operator=(const Form& copy); // assignment operator

		const std::string getName() const;
		bool getSignedStatus() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat& b);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, const Form& f);

#endif