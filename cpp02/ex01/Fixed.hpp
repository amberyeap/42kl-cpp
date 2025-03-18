/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:58:04 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/06 14:58:04 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int fixedPoint;
		static const int fractBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& toCopy);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		
		Fixed& operator=(const Fixed& toCopy);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& op, Fixed const&);

#endif