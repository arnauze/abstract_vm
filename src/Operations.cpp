# include "../inc/header.hpp"

//      Push
//      Pop
//      Dump
//      Assert
//      Add
//      Sub
//      Mul
//      Div
//      Mod
//      Print
//      Exit

void                func_push(IOperand * value) {
    stack.push(value);
    return ;
}

void                func_pop(IOperand*) {
    if (stack.size() < 1)
        throw StackEmpty();
    IOperand        *x = stack.top();
    delete x;
    stack.pop();
    return ;
}

void                func_dump(IOperand*) {
    MutantStack<IOperand*>::iterator        ite = stack.end();
    while (--ite >= stack.begin())
        std::cout << (*ite)->toString() << std::endl;
    return ;
}

void                func_assert(IOperand *value) {
    IOperand*       x = stack.top();
    if (!((x->toString() == value->toString()) && (x->getType() == value->getType()) ))
        func_exit(nullptr);
    else
        std::cout << "Assertion true" << std::endl;
    return ;
}

void                func_add(IOperand*) {
    IOperand        *a;
    IOperand        *b;
    IOperand        *res;

    if (stack.size() < 2)
        throw NotEnoughArguments();
    b = stack.top();
    stack.pop();
    a = stack.top();
    stack.pop();
    res = const_cast<IOperand*>(*a + *b);
    func_push(res);
    delete a;
    delete b;
    return ;
}

void                func_sub(IOperand*) {
    IOperand        *a;
    IOperand        *b;
    IOperand        *res;

    if (stack.size() < 2)
        throw NotEnoughArguments();
    b = stack.top();
    stack.pop();
    a = stack.top();
    stack.pop();
    res = const_cast<IOperand*>(*a - *b);
    func_push(res);
    delete a;
    delete b;
    return ;
}

void                func_mul(IOperand*) {
    IOperand        *a;
    IOperand        *b;
    IOperand        *res;

    if (stack.size() < 2)
        throw NotEnoughArguments();
    b = stack.top();
    stack.pop();
    a = stack.top();
    stack.pop();
    res = const_cast<IOperand*>(*a * *b);
    func_push(res);
    delete a;
    delete b;
    return ;
}

void                func_div(IOperand*) {
    IOperand        *a;
    IOperand        *b;
    IOperand        *res;

    if (stack.size() < 2)
        throw NotEnoughArguments();
    if ((b = stack.top())->toString() == "0")
        throw divisionByZero();
    stack.pop();
    a = stack.top();
    stack.pop();
    res = const_cast<IOperand*>(*a / *b);
    func_push(res);
    delete a;
    delete b;
    return ;
}

void                func_mod(IOperand*) {
    IOperand        *a;
    IOperand        *b;
    IOperand        *res;

    if (stack.size() < 2)
        throw NotEnoughArguments();
    if ((b = stack.top())->toString() == "0")
        throw divisionByZero();
    stack.pop();
    a = stack.top();
    stack.pop();
    res = const_cast<IOperand*>(*a % *b);
    func_push(res);
    delete a;
    delete b;
    return ;
}

void                func_print(IOperand*) {
    IOperand*       x;
	char            c;

	if (stack.empty())
		throw (StackEmpty());
	x = stack.top();
	if (x->getType() != Int8)
		throw (WrongType());
	c = std::stoi(x->toString());
	std::cout << c;
    return ;
}

void                func_exit(IOperand*) {
    exit(1);
}