/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:40:22 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/18 15:40:22 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap(); // default constructor
		FragTrap(std::string name); // parameterised constructor
		FragTrap(const FragTrap& other); // copy constructor
		~FragTrap(); // destructor

		FragTrap& operator=(const FragTrap& other); // copy assignment operator

		void highFivesGuys(void);
};

#endif