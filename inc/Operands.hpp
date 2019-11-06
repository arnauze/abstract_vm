#ifndef OPERANDS_HPP
# define OPERANDS_HPP

# include "header.hpp"

enum eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

class                                           IOperand {

    public:
        virtual int                             getPrecision( void ) const = 0;
        virtual eOperandType                    getType( void ) const = 0;
        virtual IOperand const                  *operator+( IOperand const & rhs ) const = 0;
        virtual IOperand const                  *operator-( IOperand const & rhs ) const = 0;
        virtual IOperand const                  *operator*( IOperand const & rhs ) const = 0;
        virtual IOperand const                  *operator/( IOperand const & rhs ) const = 0;
        virtual IOperand const                  *operator%( IOperand const & rhs ) const = 0;
        virtual std::string const               &toString( void ) const = 0;
        virtual ~IOperand( void ) {}

};

class                                           operandsFactory {

    public:
        IOperand const                          *createOperand( eOperandType type, std::string const & value ) const;
    
    private:
        IOperand const                          *createInt8( std::string const & value ) const;
        IOperand const                          *createInt16( std::string const & value ) const;
        IOperand const                          *createInt32( std::string const & value ) const;
        IOperand const                          *createFloat( std::string const & value ) const;
        IOperand const                          *createDouble( std::string const & value ) const;

};

class                                           AOperand : public IOperand {

    public:
        static operandsFactory                  factory;
        virtual IOperand const                  *operator+( IOperand const & rhs ) const;
        virtual IOperand const                  *operator-( IOperand const & rhs ) const;
        virtual IOperand const                  *operator*( IOperand const & rhs ) const;
        virtual IOperand const                  *operator/( IOperand const & rhs ) const;
        virtual IOperand const                  *operator%( IOperand const & rhs ) const;
        virtual std::string const               &toString( void ) const = 0;

};

class                                           Int8 : public AOperand {
    private:
        Int8(Int8 const & i);
        Int8                                    &operator=(Int8 const & i);
        Int8(void);
        std::string                             _toStr;

    public:
        char                                    value;
        Int8(char value);
        ~Int8(void);
        virtual std::string const               &toString( void ) const;
        virtual int                             getPrecision( void ) const;
        virtual eOperandType                    getType( void ) const;
};

class                                           Int16 : public AOperand {
    private:
        Int16(Int16 const & i);
        Int16                                    &operator=(Int16 const & i);
        Int16(void);
        std::string                             _toStr;

    public:
        short                                   value;
        Int16(short value);
        ~Int16(void);
        virtual std::string const               &toString( void ) const;
        virtual int                             getPrecision( void ) const;
        virtual eOperandType                    getType( void ) const;
};

class                                           Int32 : public AOperand {
    private:
        Int32(Int32 const & i);
        Int32                                    &operator=(Int32 const & i);
        Int32(void);
        std::string                             _toStr;

    public:
        int                                     value;
        Int32(int value);
        ~Int32(void);
        virtual std::string const               &toString( void ) const;
        virtual int                             getPrecision( void ) const;
        virtual eOperandType                    getType( void ) const;
};

class                                           Float : public AOperand {
    private:
        Float(Float const & i);
        Float                                    &operator=(Float const & i);
        Float(void);
        std::string                             _toStr;

    public:
        float                                   value;
        Float(float value);
        ~Float(void);
        virtual std::string const               &toString( void ) const;
        virtual int                             getPrecision( void ) const;
        virtual eOperandType                    getType( void ) const;
};

class                                           Double : public AOperand {
    private:
        Double(Double const & i);
        Double                                    &operator=(Double const & i);
        Double(void);
        std::string                             _toStr;
        
    public:
        double                                  value;
        Double(double value);
        ~Double(void);
        virtual std::string const               &toString( void ) const;
        virtual int                             getPrecision( void ) const;
        virtual eOperandType                    getType( void ) const;
};

#endif