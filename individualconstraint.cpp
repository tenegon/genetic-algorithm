#include "individualconstraint.h"

IndividualConstraint::IndividualConstraint(NumericConstraint *tConstraint, NumericConstraint *fitnessConstraint): Constraint(), tConstraint(tConstraint), fitnessConstraint(fitnessConstraint)
{

}

bool IndividualConstraint::isTFeasible(const uint &t)
{
    return tConstraint->isFeasible(t);
}

bool IndividualConstraint::isFitnessFeasible(const double &fitness)
{
    return fitnessConstraint->isFeasible(fitness);
}

bool IndividualConstraint::isFeasible(const Individual *individual)
{
    return (isTFeasible(individual->getT())) && (isFitnessFeasible(individual->getFitness()));
}

NumericConstraint *IndividualConstraint::getTConstraint() const
{
    return tConstraint;
}

void IndividualConstraint::setTConstraint(NumericConstraint *value)
{
    tConstraint = value;
}

NumericConstraint *IndividualConstraint::getFitnessConstraint() const
{
    return fitnessConstraint;
}

void IndividualConstraint::setFitnessConstraint(NumericConstraint *value)
{
    fitnessConstraint = value;
}
