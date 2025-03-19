/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:10:25 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/18 18:10:25 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	protected:
		std::string type;

	public:
		Animal(); // default constructor
		Animal(std::string type); // param constructor
		Animal(const Animal& other); // copy constructor
		virtual ~Animal(); // virtual destructor

		Animal& operator=(const Animal& other); // copy assignment operator

		std::string getType() const;
		void setType(std::string type);

		virtual void makeSound() const;
};

#endif