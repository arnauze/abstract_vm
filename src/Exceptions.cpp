# include "../inc/Exceptions.hpp"

const char * divisionByZero::what(void) const throw()  {
    return "Trying to divide by 0";
}

const char * StackEmpty::what(void) const throw()  {
    return "Trying to manipulate an empty stack.";
}

const char * WrongType::what(void) const throw()  {
    return "Wrong type.";
}

const char * NotEnoughArguments::what(void) const throw()  {
    return "Not enough arguments to execute the operation.";
}