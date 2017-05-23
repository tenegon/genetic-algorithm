#include "realindividualconstraint.h"

RealIndividualConstraint::RealIndividualConstraint(NumericConstraint *tConstraint, NumericConstraint *fitnessConstraint, NumericConstraint *sumConstraint, RealIndividual *minimum, RealIndividual *maximum): IndividualConstraint(tConstraint, fitnessConstraint), sumConstraint(sumConstraint), minimum(minimum), maximum(maximum)
{

}

bool RealIndividualConstraint::isSumFeasible(const double &sum)
{
    return sumConstraint->isFeasible(sum);
}

bool RealIndividualConstraint::isGeneFeasible(const uint &i, const double &gene)
{
    return (gene >= minimum->getGene(i)) && (gene <= maximum->getGene(i));
}

bool RealIndividualConstraint::areGenesFeasible(const std::vector<double> &genes)
{
    for(uint i = 0; i < genes.size(); i++){
        if(!isGeneFeasible(i, genes.at(i))){
            return false;
        }
    }
    return true;
}

bool RealIndividualConstraint::isFeasible(const RealIndividual *individual)
{
    return IndividualConstraint::isFeasible(individual) && isSumFeasible(individual->getSum()) && areGenesFeasible(individual->getGenes());
}

RealIndividual *RealIndividualConstraint::getMinimum() const
{
    return minimum;
}

void RealIndividualConstraint::setMinimum(RealIndividual *value)
{
    minimum = value;
}

RealIndividual *RealIndividualConstraint::getMaximum() const
{
    return maximum;
}

void RealIndividualConstraint::setMaximum(RealIndividual *value)
{
    maximum = value;
}

NumericConstraint *RealIndividualConstraint::getSumConstraint() const
{
    return sumConstraint;
}

void RealIndividualConstraint::setSumConstraint(NumericConstraint *value)
{
    sumConstraint = value;
}
