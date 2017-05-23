#include "geneticalgorithmconstraint.h"

GeneticAlgorithmConstraint::GeneticAlgorithmConstraint(uint parentsSize, uint childsSize, uint populationSize, NumericConstraint *iterationsConstraint, NumericConstraint *fitnessEvaluationConstraint, NumericConstraint *timeConstraint, uint *iterations, uint *evaluations, uint *time): Constraint(), parentsSize(parentsSize), childsSize(childsSize), populationSize(populationSize), iterationsConstraint(iterationsConstraint), fitnessEvaluationsConstraint(fitnessEvaluationConstraint), timeConstraint(timeConstraint), iterations(iterations), evaluations(evaluations), time(time)
{

}

bool GeneticAlgorithmConstraint::isFitnessEvaluatesFeasible(const uint &evaluations)
{
    return fitnessEvaluationsConstraint->isFeasible(evaluations);
}

bool GeneticAlgorithmConstraint::isIterationsFeasible(const uint &iterations)
{
    return iterationsConstraint->isFeasible(iterations);
}

bool GeneticAlgorithmConstraint::isTimeFeasible(const uint &time)
{
    return timeConstraint->isFeasible(time);
}

bool GeneticAlgorithmConstraint::isFeasible()
{
    return isFitnessEvaluatesFeasible(*evaluations) && isIterationsFeasible(*iterations) && isTimeFeasible(*time);
}

uint GeneticAlgorithmConstraint::getParentsSize() const
{
    return parentsSize;
}

void GeneticAlgorithmConstraint::setParentsSize(const uint &value)
{
    parentsSize = value;
}

uint GeneticAlgorithmConstraint::getChildsSize() const
{
    return childsSize;
}

void GeneticAlgorithmConstraint::setChildsSize(const uint &value)
{
    childsSize = value;
}

uint GeneticAlgorithmConstraint::getPopulationSize() const
{
    return populationSize;
}

void GeneticAlgorithmConstraint::setPopulationSize(const uint &value)
{
    populationSize = value;
}
