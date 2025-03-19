/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:10:57 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/18 18:10:57 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat(); // default constructor
		// Cat(std::string type); // param constructor - necessary?
		Cat(const Cat& other); // copy constructor - necessary?
		~Cat(); // destructor

		Cat& operator=(const Cat& other); // copy assignment operator - necessary?

		void makeSound() const;
};

#endif