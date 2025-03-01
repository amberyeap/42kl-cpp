/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:09:44 by ayeap             #+#    #+#             */
/*   Updated: 2025/02/25 17:09:44 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Main.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int ContactCount;

	public:
		PhoneBook();
		~PhoneBook();
		void AddContact();
		void SearchContact();
		void DisplayContact();
		std::string TrimString(std::string str);
};

#endif