/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:06:03 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/19 18:06:03 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "Materia.hpp"
# include "Character.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure& other); // copy constructor - to be used for clone()?
		~Cure();

		Cure& operator=(const Cure& other);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif