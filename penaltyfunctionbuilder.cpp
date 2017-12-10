#include "penaltyfunctionbuilder.h"

PenaltyFunctionBuilder::PenaltyFunctionBuilder()
{

}

PenaltyFunctionBuilder::~PenaltyFunctionBuilder()
{

}

SumPenaltyFunction *PenaltyFunctionBuilder::buildSumPenaltyFunction(int signal, double modifier, double exp, NumericConstraint<double> *sumConstraint)
{
    return new SumPenaltyFunction(signal, modifier, exp, sumConstraint);
}
