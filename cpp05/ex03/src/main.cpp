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
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	// intern section
    Intern intern;
    AForm* f1 = NULL;
    AForm* f2 = NULL;
    AForm* f3 = NULL;
    AForm* f4 = NULL;

    try {
        f1 = intern.makeForm("shrubbery creation", "home");
        f2 = intern.makeForm("robotomy request", "Bender");
        f3 = intern.makeForm("presidential pardon", "Marvin");
        f4 = intern.makeForm("unknown form", "???");
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    Bureaucrat boss("Boss", 1);
    Bureaucrat low("Intern", 150);

    if (f1) boss.signForm(*f1);
    if (f2) boss.signForm(*f2);
    if (f3) low.signForm(*f3);

    if (f1) boss.executeForm(*f1);
    if (f2) boss.executeForm(*f2);
    if (f3) boss.executeForm(*f3);

    AForm* forms[3] = {f1, f2, f3};

    for (int i = 0; i < 3; i++) {
        if (!forms[i]) continue;
        try {
            boss.executeForm(*forms[i]);
        }
        catch (std::exception& e) {
            std::cout << "Execution error: " << e.what() << std::endl;
        }
    }

    delete f1;
    delete f2;
    delete f3;
    delete f4;

    return 0;
}
