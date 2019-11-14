# include "../inc/Exceptions.hpp"

const char * divisionByZero::what(void) const throw()  {
    return "Trying to divide by 0";
}

const char * StackEmpty::what(void) const throw()  {
    return "Trying to manipulate an empty stack.";
}

const char * WrongType::what(void) const throw()  {
    return "Trying to print something other than a char (Int8).";
}

const char * NotEnoughArguments::what(void) const throw()  {
    return "Not enough arguments to execute the operation.";
}

const char * UnknownAction::what(void) const throw()  {
    return "Action doesn't exist.";
}

const char * NumberError::what(void) const throw()  {
    return "Synthax error in the value.";
}

const char * Overflow::what(void) const throw()  {
    return "Overflow or underflow of value.";
}

const char * WrongExit::what(void) const throw()  {
    return "Program doesn't end with an exit instruction.";
}
