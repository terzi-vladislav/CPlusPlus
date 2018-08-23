#include <iostream>
using namespace std;

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

int main() {

    Expression *a = new BinaryOperation(new Number(1), '/', new Number(2));
    Expression *b = new Number(12);
    Expression *c = new Number(11);

    Expression const * expr = new BinaryOperation(new Number(1), '/', new Number(2));
    
}