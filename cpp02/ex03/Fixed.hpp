/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:59:31 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/13 21:59:31 by ayeap            ###   ########.fr       */
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
		Fixed(); // Default constructor
		Fixed(const Fixed& toCopy); // Copy constructor
		Fixed(const int num); // Integer constructor
		Fixed(const float num); // Float constructor
		~Fixed(); // Destructor
		
		Fixed& operator=(const Fixed& toCopy); // Copy assignment operator

		// getter and setter
		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

		// comparison operators
		bool operator > (Fixed const& num) const;
		bool operator < (Fixed const& num) const;
		bool operator >= (Fixed const& num) const;
		bool operator <= (Fixed const& num) const;
		bool operator == (Fixed const& num) const;
		bool operator != (Fixed const& num) const;

		// arithemetic operators
		Fixed operator + (Fixed const& num) const;
		Fixed operator - (Fixed const& num) const;
		Fixed operator * (Fixed const& num) const;
		Fixed operator / (Fixed const& num) const;

		// increment/decrement operators
		Fixed& operator ++ (); // pre-increment
		Fixed operator ++ (int); // post-increment
		Fixed& operator -- (); // pre-decrement
		Fixed operator -- (int); // post-decrement

		static Fixed& min(Fixed &a, Fixed &b);
		static Fixed const& min(Fixed const &a, Fixed const &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static Fixed const& max(Fixed const &a, Fixed const &b);
};

std::ostream& operator<<(std::ostream& op, Fixed const&);

#endif