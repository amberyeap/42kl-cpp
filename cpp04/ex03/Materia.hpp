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

#ifndef MATERIA_HPP
# define MATERIA_HPP

#include <iostream>

#include "Character.hpp"

// abstract class because of the pure virtual function - cannot be instantiated
class AMateria {
	protected:
		std::string type; 

	public:
		AMateria();
		AMateria(std::string const & type); // param constructor

		std::string const & getType() const; // returns the materia type

		virtual AMateria* clone() const = 0; // will return a new instance of the same type
		virtual void use(ICharacter& target); // will print text depending on target
};

// pure abstract class (interface) - cannot be instantiated, contains only methods
class IMateriaSource {
	public:
		virtual ~IMateriaSource() {}; // virtual destructor

		// copies the materia passed as a parameter
		// stores in memory to CLONE later
		virtual void learnMateria(AMateria*) = 0;

		// returns a new Materia (should have a different address?)
		// returns 0 if type is unknown
		virtual AMateria* createMateria(std::string const & type) = 0;
};

// MateriaSource must be able to learn "templates" of Materias
class MateriaSource : public IMateriaSource {
	protected:
		AMateria* materiaStorage[4];

	public:
		MateriaSource();
		MateriaSource(std::string type);
		MateriaSource(const MateriaSource& other);
		~MateriaSource();

		MateriaSource& operator=(const MateriaSource& other);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const& type);
};

#endif