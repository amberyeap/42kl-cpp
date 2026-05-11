/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 02:24:33 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/11 02:24:33 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <algorithm> // for the std::find()

class UnknownItem : public std::exception {
	public:
		const char* what() const throw() {
			return "Item not found";
		}
};

template <typename T>
typename T::iterator easyfind(T& cont, int item) {
	typename T::iterator it = std::find(cont.begin(), cont.end(), item);
	if (it == cont.end())
		throw UnknownItem();
	return it;
}

#endif