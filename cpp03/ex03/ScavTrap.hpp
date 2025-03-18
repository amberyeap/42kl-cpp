/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:18:53 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/16 15:18:53 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
	public:
		ScavTrap(); // default constructor
		ScavTrap(std::string name); // parameterised constructor
		ScavTrap(const ScavTrap& other); // copy constructor
		~ScavTrap(); // destructor

		ScavTrap& operator=(const ScavTrap& other);

		void attack(const std::string &target);
		void guardGate();
};

#endif