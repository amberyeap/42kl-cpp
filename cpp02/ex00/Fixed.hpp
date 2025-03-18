/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:50:15 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/06 13:50:15 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {
	private:
		int fixedPoint;
		static const int fractBits = 8;

	public:
		Fixed();
		Fixed(Fixed& copy);
		Fixed& operator=(const Fixed& toCopy);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif