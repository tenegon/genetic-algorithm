#ifndef STOPCRITERBUILDER_H
#define STOPCRITERBUILDER_H
#include "numericstopcriter.h"

class StopCriterBuilder
{
public:
    StopCriterBuilder();
    ~StopCriterBuilder();
    template <typename T> StopCriter *buildNumericStopCriter(STOPCRITER stopCriter, T minimum, T maximum, T *value){ return new NumericStopCriter<T>(stopCriter, new NumericConstraint<T>(minimum, maximum, value));}
    template <typename T> StopCriter *buildNumericStopCriter(STOPCRITER stopCriter, NumericConstraint<T> *numericConstraint){ return new NumericStopCriter<T>(stopCriter, numericConstraint);}
};

#endif // STOPCRITERBUILDER_H
