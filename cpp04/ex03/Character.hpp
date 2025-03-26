/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:15:55 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/19 17:15:55 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "Ice.hpp"
#include "Cure.hpp"

// pure abstract class - only contains pure virtual functions
class ICharacter {
	public:
		virtual ~ICharacter(); // virtual destructor

		// pure virtual functions - to be overridden in each of the derived classes
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0; // must NOT delete the Materia - save the address of Materia before calling unequip
		virtual void use(int idx, ICharacter& target) = 0; // Materia at slot[idx] will be used
};

class Character: public ICharacter {
	protected:
		std::string name;
		AMateria* inventory[4];
		int	inventory_count;
		AMateria* floor[50];

	public:
		Character(); // default constructor
		Character(std::string name); // param constructor
		Character(const Character& other); // copy constructor
		~Character(); // destructor

		Character& operator=(const Character& other); // copy assignment operator
		// bool operator==(const Character& other) const;

		std::string const& getName() const;

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif