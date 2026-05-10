/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 23:31:49 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/10 23:31:49 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
	private:
		T *_arr;
		unsigned int _size;

	public:
		Array() : _arr(NULL), _size(0) {}

		Array(unsigned int n) : _arr(new T[n]), _size(n) {}

		Array(const Array& other) : _arr(NULL), _size(0) {
			*this = other;
		}

		~Array() {
			delete[] _arr;
		}

		Array& operator=(const Array& other) {
			if (this != &other) {
				delete[] _arr;
				this->_size = other._size;
				this->_arr = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_arr[i] = other._arr[i];
			}
			return *this;
		}

		T& operator[](unsigned int i) {
			if (i >= _size)
				throw std::out_of_range("Index out of bounds");
			return (_arr[i]);
		}

		unsigned int size() {
			return this->_size;
		}
};

#endif