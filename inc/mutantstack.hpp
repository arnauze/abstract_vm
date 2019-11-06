#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template<typename T>
class                   MutantStack : public std::stack<T> {

    public:
        MutantStack(void) : std::stack<T>() {}
        ~MutantStack(void) {}
        MutantStack(MutantStack const & mutant) { (void)mutant; return; }
        MutantStack(std::stack<T> const & stack) { (void)stack; return; }
        using std::stack<T>::operator=;
        typedef typename            std::deque<T>::iterator iterator;
        iterator                    begin(void) { return std::begin(this->c); }
        iterator                    end(void) { return std::end(this->c); }

};

#endif