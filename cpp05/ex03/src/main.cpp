/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 20:17:42 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/04 20:17:42 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        ShrubberyCreationForm shrubbery("garden");
        intern.signForm(shrubbery);
        boss.signForm(shrubbery);
        intern.executeForm(shrubbery);
        boss.executeForm(shrubbery);

        RobotomyRequestForm robotomy("Bender");
        boss.signForm(robotomy);
        boss.executeForm(robotomy);

        PresidentialPardonForm pardon("Ford");
        boss.signForm(pardon);
        boss.executeForm(pardon);

        PresidentialPardonForm unsigned_form("Arthur");
        boss.executeForm(unsigned_form);

    } catch (std::exception& e) {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }
    return 0;
}