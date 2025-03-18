/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:13:18 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/18 16:13:18 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string name;

	public:
		DiamondTrap(); // default constructor
		DiamondTrap(std::string name); // parameterised constructor
		DiamondTrap(const DiamondTrap& other); // copy constructor
		~DiamondTrap(); // destructor

		DiamondTrap& operator=(const DiamondTrap& other); // copy assignment operator

		void whoAmI();
};

#endif