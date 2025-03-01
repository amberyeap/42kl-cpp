/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:48:12 by ayeap             #+#    #+#             */
/*   Updated: 2025/02/25 14:48:12 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "Main.hpp"

class Contact {
	private:
		std::string FirstName;
		std::string LastName;
		std::string Nickname;
		std::string PhoneNumber;
		std::string DarkestSecret;

	public:
		Contact();
		~Contact();

		void setFirstName(std::string FirstName);
		void setLastName(std::string LastName);
		void setNickname(std::string Nickname);
		void setPhoneNumber(std::string PhoneNumber);
		void setDarkestSecret(std::string DarkestSecret);

		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};

#endif