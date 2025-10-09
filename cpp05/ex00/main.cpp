/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:16:15 by ayeap             #+#    #+#             */
/*   Updated: 2025/09/25 19:16:15 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	{
		std::cout << "[VALID BUREAUCRATS]" << std::endl;

		try {
			Bureaucrat bob("bob", 50);
			Bureaucrat bib("bib", 1);
			Bureaucrat bub("bub", 150);
			Bureaucrat basic;

			std::cout << bob << std::endl;
			std::cout << bib << std::endl;
			std::cout << bub << std::endl;
			std::cout << basic << std::endl;

		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << "[INVALID BUREAUCRATS]" << std::endl;

		try {
			Bureaucrat bob("bob", 151);
			std::cout << bob << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		try {
			Bureaucrat bib("bib", 0);
			std::cout << bib << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		try {
			Bureaucrat bub("bub", 1500);
			std::cout << bub << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		try {
			Bureaucrat bab("bab", -6);
			std::cout << bab << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << "[INCREMENTING GRADES]" << std::endl;

		try {
			Bureaucrat bob("bob", 50);
			std::cout << bob << std::endl;

			bob.incrementGrade();
			std::cout << bob << std::endl;

		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		try {
			Bureaucrat bib("bib", 1);
			std::cout << bib << std::endl;

			bib.incrementGrade(); // should throw
			std::cout << bib << std::endl;

		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << "[DECREMENTING GRADES]" << std::endl;

		try {
			Bureaucrat bob("bob", 150);
			std::cout << bob << std::endl;

			bob.decrementGrade(); // should throw
			std::cout << bob << std::endl;

		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		try {
			Bureaucrat bib("bib", 1);
			std::cout << bib << std::endl;

			bib.decrementGrade();
			std::cout << bib << std::endl;

		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
}
