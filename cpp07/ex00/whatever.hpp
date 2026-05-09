/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:12:54 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/07 19:12:54 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
T min(const T x, const T y) {
	if (x == y)
		return y;
	if (x < y)
		return x;
	return y;
}

template <typename T>
T max(const T x, const T y) {
	if (x > y)
		return x;
	return y;
}

#endif