# include "inc/header.hpp"

int main(void) {

    class Int8          x(42);
    class Int16         y(150);
    class Int32         z(953241);
    MutantStack<IOperand*>         stack;

    stack.push(&x);
    stack.push(&y);
    stack.push(&z);

    MutantStack<IOperand*>::iterator        it = stack.begin();
    MutantStack<IOperand*>::iterator        ite = stack.end();

    for(; it != ite; it++) {
        std:: cout << (*it)->toString() << std::endl;
    }

    return (0);

}