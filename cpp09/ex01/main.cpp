/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:01:58 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/15 14:01:58 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error: Invalid arguments" << std::endl;
		return 1;
	}

	RPN rpn;

	try {
		rpn.mathIt(argv[1]);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

// test cases

/*
./RPN "3 4 +"
# expected: 7

./RPN "8 2 /"
# expected: 4

./RPN "5 3 -"
# expected: 2

./RPN "3 4 + 2 *"
# expected: 14

./RPN "8 2 / 3 -"
# expected: 1

./RPN "7 3 2 * +"
# expected: 13

./RPN "1 2 3 + *"
# expected: 5

./RPN "9 8 * 7 2 - /"
# expected: 14  (72 / 5... wait, 9*8=72, 7-2=5, 72/5=14 in integer division)
# actually: 14

./RPN "0 5 +"
# expected: 5

./RPN "1 1 -"
# expected: 0

./RPN "9 9 *"
# expected: 81

./RPN "1 2 + 3 4 + *"
# expected: 21  (1+2=3, 3+4=7, 3*7=21)

[ERROR HANDLING]
./RPN "4 +"
# expected: Error (only one operand for +)

./RPN "1 2"
# expected: Error (two values left on stack)

./RPN "1 0 /"
# expected: Error: cannot divide by zero

./RPN "1 a +"
# expected: Error: invalid token

./RPN ""
# expected: Error (empty expression or invalid)

./RPN "+"
# expected: Error (operator with nothing on stack)

./RPN
# expected: usage error

./RPN "1 2 +" "3 4 +"
# expected: usage error (too many args) or only first is processed — check your subject
*/