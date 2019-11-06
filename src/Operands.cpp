# include "../inc/Exceptions.hpp"
# include "../inc/Operands.hpp"

// ----------------------------------------------------------------------------------------------------------------------------
//
//                              Definition of the operandsFactory class

IOperand const                  *operandsFactory::createInt8( std::string const & value ) const {
    try {
        std::stoi(value);
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    int                         newValue = std::stoi(value);
    if (newValue > std::numeric_limits<char>::max() || newValue < std::numeric_limits<char>::min())
        throw std::exception();
    return (new class Int8(static_cast<char>(newValue)));
}

IOperand const                  *operandsFactory::createInt16( std::string const & value ) const {
    try {
        std::stoi(value);
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    int                         newValue = std::stoi(value);
    if (newValue > std::numeric_limits<short>::max() || newValue < std::numeric_limits<short>::min())
        throw std::exception();
    return (new class Int16(static_cast<short>(newValue)));
}

IOperand const                  *operandsFactory::createInt32( std::string const & value ) const {
    try {
        std::stoi(value);
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    int                         newValue = std::stoi(value);
    if (newValue > std::numeric_limits<int>::max() || newValue < std::numeric_limits<int>::min())
        throw std::exception();
    return (new class Int32(newValue));
}

IOperand const                  *operandsFactory::createFloat( std::string const & value ) const {
    try {
        std::stof(value);
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    float                       newValue = std::stof(value);
    if (newValue > std::numeric_limits<float>::max() || newValue < std::numeric_limits<float>::min())
        throw std::exception();
    return (new class Float(newValue));
}

IOperand const                  *operandsFactory::createDouble( std::string const & value ) const {
    try {
        std::stod(value);
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    double                      newValue = std::stod(value);
    if (newValue > std::numeric_limits<double>::max() || newValue < std::numeric_limits<double>::min())
        throw std::exception();
    return (new class Double(newValue));
}

IOperand const                  *operandsFactory::createOperand(eOperandType type, std::string const & value) const {
    switch(type) {
        case Int8:
            return operandsFactory::createInt8(value);
        case Int16:
            return operandsFactory::createInt16(value);
        case Int32:
            return operandsFactory::createInt32(value);
        case Float:
            return operandsFactory::createFloat(value);
        case Double:
            return operandsFactory::createDouble(value);
        default:
            return nullptr;
    }
}

// ----------------------------------------------------------------------------------------------------------------------------
//
//                              Definition of the AOperand abstract class

operandsFactory                 AOperand::factory;

IOperand const                  *AOperand::operator+( IOperand const & rhs ) const {
    eOperandType                type = std::max(this->getType(), rhs.getType());
    std::ostringstream          s;
    s << (std::stod(this->toString()) + std::stod(rhs.toString()));
    return this->factory.createOperand(type, s.str());
}

IOperand const                  *AOperand::operator-( IOperand const & rhs ) const {
    eOperandType                type = std::max(this->getType(), rhs.getType());
    std::ostringstream          s;
    s << (std::stod(this->toString()) - std::stod(rhs.toString()));
    return this->factory.createOperand(type, s.str());
}

IOperand const                  *AOperand::operator*( IOperand const & rhs ) const {
    eOperandType                type = std::max(this->getType(), rhs.getType());
    std::ostringstream          s;
    s << (std::stod(this->toString()) * std::stod(rhs.toString()));
    return this->factory.createOperand(type, s.str());
}

IOperand const                  *AOperand::operator/( IOperand const & rhs ) const {
    eOperandType                type = std::max(this->getType(), rhs.getType());
    std::ostringstream          s;
    if (std::stoi(rhs.toString()) == 0)
        throw divisionByZero();
    s << (std::stod(this->toString()) / std::stod(rhs.toString()));
    return this->factory.createOperand(type, s.str());
}

IOperand const                  *AOperand::operator%( IOperand const & rhs ) const {
    eOperandType                type = std::max(this->getType(), rhs.getType());
    std::ostringstream          s;
    if (std::stoi(rhs.toString()) == 0)
        throw divisionByZero();
    s << (std::stoi(this->toString()) % std::stoi(rhs.toString()));
    return this->factory.createOperand(type, s.str());
}

// ----------------------------------------------------------------------------------------------------------------------------
//
//                              Definition of the Int8 class

Int8::Int8(void) :  _toStr(""), value(0) { return ; }
Int8::Int8(char value) : value(value) {
    std::ostringstream          s;
    s << value;
    this->_toStr = s.str();
    return ;
}
Int8::~Int8(void) { return ; }
std::string const               &Int8::toString(void) const { return this->_toStr; }
int                             Int8::getPrecision(void) const { return 0; }
eOperandType                    Int8::getType(void) const { return eOperandType::Int8; }

// ----------------------------------------------------------------------------------------------------------------------------
//
//                              Definition of the Int16 class

Int16::Int16(void) :  _toStr(""), value(0) { return ; }
Int16::Int16(short value) : value(value) {
    std::ostringstream          s;
    s << value;
    this->_toStr = s.str();
    return ;
}
Int16::~Int16(void) { return ; }
std::string const               &Int16::toString(void) const { return this->_toStr; }
int                             Int16::getPrecision(void) const { return 0; }
eOperandType                    Int16::getType(void) const { return eOperandType::Int16; }

// ----------------------------------------------------------------------------------------------------------------------------
//
//                              Definition of the Int32 class

Int32::Int32(void) :  _toStr(""), value(0) { return ; }
Int32::Int32(int value) : value(value) {
    std::ostringstream          s;
    s << value;
    this->_toStr = s.str();
    return ;
}
Int32::~Int32(void) { return ; }
std::string const               &Int32::toString(void) const { return this->_toStr; }
int                             Int32::getPrecision(void) const { return 0; }
eOperandType                    Int32::getType(void) const { return eOperandType::Int32; }

// ----------------------------------------------------------------------------------------------------------------------------
//
//                              Definition of the Float class

Float::Float(void) :  _toStr(""), value(0) { return ; }
Float::Float(float value) : value(value) {
    std::ostringstream          s;
    s << value;
    this->_toStr = s.str();
    return ;
}
Float::~Float(void) { return ; }
std::string const               &Float::toString(void) const { return this->_toStr; }
int                             Float::getPrecision(void) const { return 7; }
eOperandType                    Float::getType(void) const { return eOperandType::Float; }

// ----------------------------------------------------------------------------------------------------------------------------
//
//                              Definition of the Double class

Double::Double(void) :  _toStr(""), value(0) { return ; }
Double::Double(double value) : value(value) {
    std::ostringstream          s;
    s << value;
    this->_toStr = s.str();
    return ;
}
Double::~Double(void) { return ; }
std::string const               &Double::toString(void) const { return this->_toStr; }
int                             Double::getPrecision(void) const { return 15; }
eOperandType                    Double::getType(void) const { return eOperandType::Double; }

// ----------------------------------------------------------------------------------------------------------------------------






