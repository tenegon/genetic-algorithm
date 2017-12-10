#ifndef NUMERICSTOPCRITER_H
#define NUMERICSTOPCRITER_H
#include "stopcriter.h"
#include "numericconstraint.h"

template <typename T>
class NumericStopCriter : public StopCriter
{
protected:
    NumericConstraint<T> *numericConstraint;
public:
    NumericStopCriter(STOPCRITER stopCriter, NumericConstraint<T> *numericConstraint): StopCriter(stopCriter), numericConstraint(numericConstraint){}
    ~NumericStopCriter(){delete numericConstraint;}
    bool meets(){return numericConstraint->isFeasible();}
    void print(std::ostream& os) const{StopCriter::print(os);os << " " << *numericConstraint;}
    void setValue(T *value){numericConstraint->setValue(value);}
    void setMinimum(const T &value){numericConstraint->setMinimum(value);}
    void setMaximum(const T &value){numericConstraint->setMaximum(value);}
    T getMinimum() const{return numericConstraint->getMinimum();}
    T getMaximum() const{return numericConstraint->getMaximum();}
};

#endif // NUMERICSTOPCRITER_H
