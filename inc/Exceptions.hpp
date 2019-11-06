#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include "header.hpp"

struct                      divisionByZero : public std::exception {
    const char* what() const throw();
};

#endif