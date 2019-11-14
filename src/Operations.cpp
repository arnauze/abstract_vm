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
    logs.open("Logs", std::ios::out | std::ios::app);
    logs << "Push requested:" << std::endl;
    stack.push(value);
    logs << "Pushing " << value->toString() << " to the stack" << std::endl << std::endl;
    logs.close();
    return ;
}

void                func_pop(IOperand*) {
    logs.open("Logs", std::ios::out | std::ios::app);
    logs << "Pop requested:" << std::endl;
    if (stack.size() < 1) {
        logs << "Trying to manipulate an empty stack." << std::endl << std::endl;
        throw StackEmpty();
    }
    IOperand        *x = stack.top();
    logs << "Popping " << x->toString() << " from the stack" << std::endl << std::endl;
    delete x;
    stack.pop();
    logs.close();
    return ;
}

void                func_dump(IOperand*) {
    logs.open("Logs", std::ios::out | std::ios::app);
    logs << "Dump requested:" << std::endl;
    if (stack.size() < 1) {
        logs << "Trying to manipulate an empty stack." << std::endl << std::endl;
        throw StackEmpty();
    }
    MutantStack<IOperand*>::iterator        ite = stack.end();
    while (--ite >= stack.begin()) {
        std::cout << (*ite)->toString() << std::endl;
        logs << (*ite)->toString() << std::endl;
    }
    logs << std::endl;
    logs.close();
    return ;
}

void                func_assert(IOperand *value) {
    logs.open("Logs", std::ios::out | std::ios::app);
    logs << "Assert requested:" << std::endl;
    IOperand*       x = stack.top();
    if (!((x->toString() == value->toString()) && (x->getType() == value->getType()) )) {
        logs << "Wrong assertion" << std::endl;
        logs.close();
        func_exit(nullptr);
    }
    else {
        std::cout << "Assertion true" << std::endl;
        logs << "Assertion true" << std::endl << std::endl;
    }
    logs.close();
    return ;
}

void                func_add(IOperand*) {
    IOperand        *a;
    IOperand        *b;
    IOperand        *res;

    logs.open("Logs", std::ios::out | std::ios::app);
    logs << "Addition requested:" << std::endl;
    if (stack.size() < 2) {
        logs << "Not enough arguments to execute the operation." << std::endl << std::endl;
        throw NotEnoughArguments();
    }
    b = stack.top();
    stack.pop();
    a = stack.top();
    stack.pop();
    logs << a->toString() << " + " << b->toString() << " = ";
    res = const_cast<IOperand*>(*a + *b);
    logs << res->toString() << std::endl << std::endl;
    func_push(res);
    delete a;
    delete b;
    logs.close();
    return ;
}

void                func_sub(IOperand*) {
    IOperand        *a;
    IOperand        *b;
    IOperand        *res;

    logs.open("Logs", std::ios::out | std::ios::app);
    logs << "Substraction requested:" << std::endl;
    if (stack.size() < 2) {
        logs << "Not enough arguments to execute the operation." << std::endl << std::endl;
        throw NotEnoughArguments();
    }
    b = stack.top();
    stack.pop();
    a = stack.top();
    stack.pop();
    logs << a->toString() << " - " << b->toString() << " = ";
    res = const_cast<IOperand*>(*a - *b);
    logs << res->toString() << std::endl << std::endl;
    func_push(res);
    delete a;
    delete b;
    logs.close();
    return ;
}

void                func_mul(IOperand*) {
    IOperand        *a;
    IOperand        *b;
    IOperand        *res;

    logs.open("Logs", std::ios::out | std::ios::app);
    logs << "Multiplication requested:" << std::endl;
    if (stack.size() < 2) {
        logs << "Not enough arguments to execute the operation." << std::endl << std::endl;
        throw NotEnoughArguments();
    }
    b = stack.top();
    stack.pop();
    a = stack.top();
    stack.pop();
    logs << a->toString() << " * " << b->toString() << " = ";
    res = const_cast<IOperand*>(*a * *b);
    logs << res->toString() << std::endl << std::endl;
    func_push(res);
    delete a;
    delete b;
    logs.close();
    return ;
}

void                func_div(IOperand*) {
    IOperand        *a;
    IOperand        *b;
    IOperand        *res;

    logs.open("Logs", std::ios::out | std::ios::app);
    logs << "Divition requested:" << std::endl;
    if (stack.size() < 2) {
        logs << "Not enough arguments to execute the operation." << std::endl << std::endl;
        throw NotEnoughArguments();
    }
    if ((b = stack.top())->toString() == "0") {
        logs << "Trying to divide by 0" << std::endl << std::endl;
        throw divisionByZero();
    }
    stack.pop();
    a = stack.top();
    stack.pop();
    logs << a->toString() << " / " << b->toString() << " = ";
    res = const_cast<IOperand*>(*a / *b);
    logs << res->toString() << std::endl << std::endl;
    func_push(res);
    delete a;
    delete b;
    logs.close();
    return ;
}

void                func_mod(IOperand*) {
    IOperand        *a;
    IOperand        *b;
    IOperand        *res;

    logs.open("Logs", std::ios::out | std::ios::app);
    logs << "Modulo requested:" << std::endl;
    if (stack.size() < 2) {
        logs << "Not enough arguments to execute the operation." << std::endl << std::endl;
        throw NotEnoughArguments();
    }
    if ((b = stack.top())->toString() == "0") {
        logs << "Trying to divide by 0" << std::endl << std::endl;
        throw divisionByZero();
    }
    stack.pop();
    a = stack.top();
    stack.pop();
    logs << a->toString() << " % " << b->toString() << " = ";
    res = const_cast<IOperand*>(*a % *b);
    logs << res->toString() << std::endl << std::endl;
    func_push(res);
    delete a;
    delete b;
    logs.close();
    return ;
}

void                func_print(IOperand*) {
    IOperand*       x;
	char            c;

    logs.open("Logs", std::ios::out | std::ios::app);
    logs << "Print requested:" << std::endl;
	if (stack.empty()) {
        logs << "Stack is empty" << std::endl << std::endl;
		throw (StackEmpty());
    }
	x = stack.top();
	if (x->getType() != Int8) {
        logs << "Trying to print something other than a char (Int8)." << std::endl << std::endl;
		throw (WrongType());
    }
	c = std::stoi(x->toString());
    std::cout << c;
    logs << c << std::endl << std::endl;
    logs.close();
    return ;
}

void                func_exit(IOperand*) {
    logs.open("Logs", std::ios::out | std::ios::app);
    logs << "Exiting program." << std::endl;
    logs.close();
    exit(1);
}