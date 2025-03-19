/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:09:44 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/19 15:09:44 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	protected:
		std::string ideas[100];

	public:
		Brain();
		// Brain(std::string idea);
		Brain(const Brain& other);
		~Brain();

		Brain& operator=(const Brain& other);
};

#endif