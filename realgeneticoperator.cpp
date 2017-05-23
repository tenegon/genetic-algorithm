#include "realgeneticoperator.h"

RealGeneticOperator::RealGeneticOperator(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint): GeneticOperator(rate, generation), realIndividualConstraint(realIndividualConstraint)
{

}

RealIndividualConstraint *RealGeneticOperator::getRealIndividualConstraint() const
{
    return realIndividualConstraint;
}

void RealGeneticOperator::setRealIndividualConstraint(RealIndividualConstraint *value)
{
    realIndividualConstraint = value;
}
