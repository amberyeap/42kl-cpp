#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

/* subclass std::stack - needed for this exercise 
but discouraged overall because of the lack of virtual destructors */

// std::stack has an underlying container which by default is std::deque

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() {}
        MutantStack(const MutantStack& other) : std::stack<T>(other) {}
        ~MutantStack() {}

        MutantStack& operator=(const MutantStack& other) {
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}
};

#endif