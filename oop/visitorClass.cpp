#include <iostream>
using namespace std;

struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
    virtual ~Visitor() { }
};

struct Expression {
    virtual double evaluate() const = 0;
    virtual void visit(Visitor * visitor) const  = 0;
    virtual ~Expression() {}
};

struct Number : Expression {
    Number(double value)
        : value(value)
    {}
    double evaluate() const {
        return value;
    }
    void visit(Visitor * visitor) const { 
        visitor->visitNumber(this);
    }
    double get_value() const {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression {
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right){}
    double evaluate() const {
        if (op == '+')
            return left->evaluate() + right->evaluate();
        else if (op == '-')
            return left->evaluate() - right->evaluate();
        else if (op == '*')
            return left->evaluate() * right->evaluate();
        else if (op == '/')
            return left->evaluate() / right->evaluate();
        }

    void visit(Visitor * visitor) const {
        visitor->visitBinaryOperation(this);
    }

    Expression const * get_left()  const {
        return left;
    }
    Expression const * get_right() const {
        return right;
    }
    char get_op() const {
        return op;
    }

    ~BinaryOperation(){
        delete left;
        delete right;
    }

private:
    Expression const * left;
    Expression const * right;
    char op;
};

bool check_equals(Expression const *left, Expression const *right) {
    long **leftVT = (long **)&left;
    long **rightVT = (long **)&right;
    
    if (leftVT[0][0] == rightVT[0][0])
        return true;
    return false;
}

struct PrintVisitor : Visitor {
    void visitNumber(Number const * number)
    {
        std::cout << number->get_value();
        
    }

    void visitBinaryOperation(BinaryOperation const * bop)
    {
        std::cout << "(";
        bop->get_left()->visit(this);
        std::cout << ")" << bop->get_op() << "(";
        bop->get_right()->visit(this);
        std::cout << ")";
    }
};

int main() {

    Expression *a = new BinaryOperation(new Number(1), '/', new Number(2));
    Expression *b = new Number(12);
    Expression *c = new Number(11);

    Expression * expr = new BinaryOperation(new Number(10.0), '*',
                                             (new BinaryOperation(new Number(7.0), '+', new Number(3.0))));
    PrintVisitor visitor;
    expr->visit(&visitor);
    
}