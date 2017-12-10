#include "sumpenaltyfunction.h"

SumPenaltyFunction::SumPenaltyFunction(int signal, double modifier, double exp, NumericConstraint<double> *sumConstraint): PenaltyFunction(signal, modifier), exp(exp), sumConstraint(sumConstraint)
{

}

SumPenaltyFunction::~SumPenaltyFunction()
{
    delete sumConstraint;
}

void SumPenaltyFunction::penalize(Individual *individual)
{
    double sum = dynamic_cast<RealIndividual*>(individual)->getSum();
    if(!sumConstraint->isFeasible(sum)){
        double fitness = individual->getFitness();
        fitness += penalty(sum);
        individual->setFitness(fitness);
    }
}

double SumPenaltyFunction::penalty(const double &sum)
{
    double absValue1 = abs(sum - sumConstraint->getMinimum());
    double absValue2 = abs(sum - sumConstraint->getMaximum());
    double base = (absValue1 + absValue2) / 2.0;
    return signal * (pow(base, exp) + modifier);
}

void SumPenaltyFunction::print(std::ostream &os) const
{
    os << "Sum ";
    PenaltyFunction::print(os);
}

NumericConstraint<double> *SumPenaltyFunction::getSumConstraint() const
{
    return sumConstraint;
}

void SumPenaltyFunction::setSumConstraint(NumericConstraint<double> *value)
{
    sumConstraint = value;
}

double SumPenaltyFunction::getExp() const
{
    return exp;
}

void SumPenaltyFunction::setExp(double value)
{
    exp = value;
}
