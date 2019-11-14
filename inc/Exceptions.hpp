#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include "header.hpp"

struct                      divisionByZero : public std::exception {
    const char* what() const throw();
};

struct                      StackEmpty : public std::exception {
    const char* what() const throw();
};

struct                      WrongType : public std::exception {
    const char* what() const throw();
};

struct                      NotEnoughArguments : public std::exception {
    const char* what() const throw();
};

struct                      UnknownAction : public std::exception {
    const char* what() const throw();
};

struct                      NumberError : public std::exception {
    const char* what() const throw();
};

struct                      Overflow : public std::exception {
    const char* what() const throw();
};

struct                      WrongExit : public std::exception {
    const char* what() const throw();
};

#endif