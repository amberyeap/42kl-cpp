/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:10:59 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/18 18:10:59 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* dogBrain;

	public:
		Dog(); // default constructor
		// Dog(std::string type); // param constructor - necessary?
		Dog(const Dog& other); // copy constructor - necessary?
		~Dog(); // destructor

		Dog& operator=(const Dog& other); // copy assignment operator - necessary?

		void makeSound() const;
};

#endif