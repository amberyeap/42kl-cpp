/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:07:44 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/19 17:07:44 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main() {
	IMateriaSource	*src = new MateriaSource();
	AMateria		*tmp;
	ICharacter		*bob = new Character("Bob");

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	tmp = src->createMateria("ICE");
	bob->equip(tmp);
	tmp = src->createMateria("CURE");
	bob->equip(tmp);
	tmp = src->createMateria("ICE");
	bob->equip(tmp);

	bob->use(0, *bob);
	bob->use(1, *bob);
	bob->use(2, *bob);
	bob->use(3, *bob);

	bob->unequip(1);
	
	bob->use(0, *bob);
	bob->use(1, *bob);
	bob->use(2, *bob);

	src->getMemory();

	delete src;
	delete bob;
	return 0;
}

// int main() {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");

// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;

// 	return 0;
// }