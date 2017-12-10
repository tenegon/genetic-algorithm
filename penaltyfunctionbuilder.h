#ifndef PENALTYFUNCTIONBUILDER_H
#define PENALTYFUNCTIONBUILDER_H
#include "sumpenaltyfunction.h"

class PenaltyFunctionBuilder
{
public:
    PenaltyFunctionBuilder();
    ~PenaltyFunctionBuilder();
    SumPenaltyFunction *buildSumPenaltyFunction(int signal, double modifier, double exp, NumericConstraint<double> *sumConstraint);
};

#endif // PENALTYFUNCTIONBUILDER_H
