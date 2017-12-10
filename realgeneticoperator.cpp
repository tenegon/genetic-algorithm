#include "realgeneticoperator.h"

RealGeneticOperator::RealGeneticOperator(double rate, Generation *generation, IndividualConstraint *individualConstraint): GeneticOperator(rate, generation), individualConstraint(individualConstraint)
{

}

RealGeneticOperator::~RealGeneticOperator()
{
    individualConstraint = 0;
}

IndividualConstraint *RealGeneticOperator::getRealIndividualConstraint() const
{
    return individualConstraint;
}

void RealGeneticOperator::setRealIndividualConstraint(IndividualConstraint *value)
{
    individualConstraint = value;
}
