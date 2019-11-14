#ifndef HEADER_HPP
# define HEADER_HPP

# include <string>
# include <iostream>
# include <vector>
# include <sstream>
# include <fstream>
# include <exception>
# include <map>
# include <stdio.h>

# include "Operands.hpp"
# include "Exceptions.hpp"
# include "mutantstack.hpp"

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

static MutantStack<IOperand*>       stack;
static std::ofstream                 logs;

static std::map<std::string, void (*)(IOperand*)> dispatch_table  = {
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
    {"exit", &func_exit}
};

static std::map<std::string, eOperandType> types = {
    {"int8", Int8},
    {"int16", Int16},
    {"int32", Int32},
    {"float", Float},
    {"double", Double}
};

static  std::string actions[11] = {
    "push",
    "pop",
    "dump",
    "assert",
    "add",
    "sub",
    "mul",
    "div",
    "mod",
    "print",
    "exit"
};

#endif