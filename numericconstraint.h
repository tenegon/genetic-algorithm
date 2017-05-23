#ifndef NUMERICCONSTRAINT_H
#define NUMERICCONSTRAINT_H
#include "constraint.h"

class NumericConstraint : public Constraint
{
protected:
    double minimum;
    double maximum;
    double *value;
public:
    NumericConstraint(double minimum, double maximum, double *value);
    bool isFeasible();
    bool isFeasible(const double &value);
    double getMinimum() const;
    void setMinimum(double value);
    double getMaximum() const;
    void setMaximum(double value);
};

#endif // NUMERICCONSTRAINT_H
