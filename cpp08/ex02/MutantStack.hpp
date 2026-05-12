#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

class MutantStack {

    public:
        MutantStack();
        MutantStack(const MutantStack& other);
        ~MutantStack();

        MutantStack& operator=(const MutantStack& other);
};

#endif