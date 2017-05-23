#ifndef REALCROSSOVER_H
#define REALCROSSOVER_H
#include "realgeneticoperator.h"
#include "crossover.h"

class RealCrossover : public RealGeneticOperator, public Crossover
{
public:
    RealCrossover(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint);
    void cross();
    virtual void apply();
};

#endif // REALCROSSOVER_H
