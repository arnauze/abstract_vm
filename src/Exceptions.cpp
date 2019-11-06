# include "../inc/Exceptions.hpp"

const char * divisionByZero::what(void) const throw()  {
    return "Trying to divide by 0";
}
