/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:05:13 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/19 18:05:13 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "Materia.hpp"
# include "Character.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice& other);
		~Ice();

		Ice& operator=(const Ice& other);

		AMateria* clone() const; 
		void use(ICharacter& target);
};

#endif