/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:34:56 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/19 14:34:56 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat& other);
		~WrongCat();

		WrongCat& operator=(const WrongCat& other);

		void makeSound() const;
};

#endif