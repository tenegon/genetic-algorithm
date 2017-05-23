#ifndef NUMERICSTOPCRITER_H
#define NUMERICSTOPCRITER_H
#include "stopcriter.h"
#include "numericconstraint.h"

class NumericStopCriter : public StopCriter
{
protected:
    NumericConstraint *numericConstraint;
public:
    NumericStopCriter(NumericConstraint *numericConstraint);
    bool meets();
};

#endif // NUMERICSTOPCRITER_H
