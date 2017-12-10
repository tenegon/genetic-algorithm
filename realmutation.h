#ifndef REALMUTATION_H
#define REALMUTATION_H
#include "realgeneticoperator.h"
#include "mutation.h"

class RealMutation : public RealGeneticOperator, public Mutation
{
protected:
    RealIndividual *mutant;
public:
    RealMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint);
    ~RealMutation();
    void mutate();
    void apply();
};

#endif // REALMUTATION_H
