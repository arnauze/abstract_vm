#ifndef HEADER_HPP
# define HEADER_HPP

# include <string>
# include <iostream>
# include <vector>
# include <sstream>
# include <exception>
# include <map>

# include "Operands.hpp"
# include "Exceptions.hpp"
# include "mutantstack.hpp"

static MutantStack<IOperand*>       stack;

void                                func_push(IOperand * value);
void                                func_pop(IOperand *);
void                                func_dump(IOperand *);
void                                func_assert(IOperand *value);
void                                func_add(IOperand *);
void                                func_sub(IOperand *);
void                                func_mul(IOperand *);
void                                func_div(IOperand *);
void                                func_mod(IOperand *);
void                                func_print(IOperand *);
void                                func_exit(IOperand *);

static std::map<std::string, void (*)(IOperand*)> dispatch_table = {
    {"push", &func_push},
    {"pop", &func_pop},
    {"dump", &func_dump},
    {"assert", &func_assert},
    {"add", &func_add},
    {"sub", &func_sub},
    {"mul", &func_mul},
    {"div", &func_div},
    {"mod", &func_mod},
    {"print", &func_print},
    {"exit", &func_push},
};

#endif