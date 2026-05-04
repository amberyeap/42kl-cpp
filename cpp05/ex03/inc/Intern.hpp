/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 21:46:57 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/04 21:46:57 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeForm(std::string formName, std::string target);

		static AForm* createShrubberyCreation(std::string target);
		static AForm* createRobotomyRequest(std::string target);
		static AForm* createPresidentialPardon(std::string target);

		class UnknownFormException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif