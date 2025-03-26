/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:18:18 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/25 13:18:18 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// pure abstract class (interface) - cannot be instantiated, contains only methods
class IMateriaSource {
	public:
		virtual ~IMateriaSource(); // virtual destructor

		// copies the materia passed as a parameter
		// stores in memory to CLONE later
		virtual void learnMateria(AMateria*) = 0;

		// returns a new Materia (should have a different address?)
		// returns 0 if type is unknown
		virtual AMateria* createMateria(std::string const & type) = 0;

		virtual void getMemory() const = 0;
};

// MateriaSource must be able to learn "templates" of Materias
class MateriaSource : public IMateriaSource {
	protected:
		AMateria* materiaStorage[4];
		int storage_count;

	public:
		MateriaSource();
		// MateriaSource(std::string type);
		MateriaSource(const MateriaSource& other);
		virtual ~MateriaSource();

		MateriaSource& operator=(const MateriaSource& other);

		virtual void getMemory() const;

		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const& type);
};
