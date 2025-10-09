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
#include "Form.hpp"

int main() {
	std::cout << "========== [VALID BUREAUCRATS AND FORMS] ==========" << std::endl;
	try {
		Bureaucrat bob("Bob", 50);
		Bureaucrat alice("Alice", 1);
		Form taxForm("Tax Form", 75, 100);
		Form topSecret("Top Secret", 1, 1);

		std::cout << bob << std::endl;
		std::cout << alice << std::endl;
		std::cout << taxForm << std::endl;
		std::cout << topSecret << std::endl;

		std::cout << "\n[ATTEMPTS TO SIGN]" << std::endl;
		bob.signForm(taxForm);      // should succeed
		bob.signForm(topSecret);    // should fail (too low)
		alice.signForm(topSecret);  // should succeed

		std::cout << "\n[FINAL FORM STATES]" << std::endl;
		std::cout << taxForm << std::endl;
		std::cout << topSecret << std::endl;
	} 
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========== [INVALID FORM CREATION] ==========" << std::endl;
	try {
		Form badForm("Impossible Form", 0, 50); // grade too high
	} 
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Form badForm2("Lazy Form", 151, 100); // grade too low
	} 
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========== [GRADE ADJUSTMENT TESTS] ==========" << std::endl;
	try {
		Bureaucrat jim("Jim", 2);
		std::cout << jim << std::endl;
		jim.incrementGrade(); // should make grade 1
		std::cout << jim << std::endl;
		jim.incrementGrade(); // should throw
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat tim("Tim", 149);
		std::cout << tim << std::endl;
		tim.decrementGrade(); // should make grade 150
		std::cout << tim << std::endl;
		tim.decrementGrade(); // should throw
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========== [PROGRAM END] ==========" << std::endl;
	return 0;
}
