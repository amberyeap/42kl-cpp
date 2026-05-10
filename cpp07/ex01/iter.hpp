/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:32:18 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/09 15:32:18 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void iter(T *arr, const int len, F func) {
	for (int i = 0; i < len; i++) {
		func(arr[i]);
	}
}

#endif