#ifndef NUMERICCONSTRAINT_H
#define NUMERICCONSTRAINT_H
#include "constraint.h"

template <typename T>
class NumericConstraint : public Constraint
{
protected:
    T minimum;
    T maximum;
    T *value;
public:
    NumericConstraint(T minimum, T maximum): minimum(minimum), maximum(maximum){}
    NumericConstraint(T minimum, T maximum, T *value): minimum(minimum), maximum(maximum), value(value){}
    ~NumericConstraint(){}
    bool isFeasible(){return (minimum <= (*value)) && (maximum >= (*value));}
    bool isFeasible(const T &value){return (minimum <= value) && (maximum >= value);}
    void print(std::ostream& os) const{
        Constraint::print(os);
        os << " (" << minimum  << ", " << maximum << ")";
}
    void setMinMax(const T &minimum, const T &maximum){
        this->minimum = minimum;
        this->maximum = maximum;
    }
    T getMinimum() const{return minimum;}
    void setMinimum(T value){minimum = value;}
    T getMaximum() const{return maximum;}
    void setMaximum(T value){maximum = value;}
    T *getValue() const{return value;}
    void setValue(T *value){this->value = value;}
};

#endif // NUMERICCONSTRAINT_H
