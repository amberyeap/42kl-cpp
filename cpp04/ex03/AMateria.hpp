/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:08:37 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/19 17:08:37 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

// #include "Character.hpp"

class ICharacter;

// abstract class because of the pure virtual function - cannot be instantiated
class AMateria {
	protected:
		std::string type; 

	public:
		AMateria();
		AMateria(std::string const & type); // param constructor
		AMateria(const AMateria& other);
		~AMateria();

		AMateria& operator=(const AMateria& other);

		std::string const & getType() const; // returns the materia type

		virtual AMateria* clone() const = 0; // will return a new instance of the same type
		virtual void use(ICharacter& target); // will print text depending on target
};

#endif