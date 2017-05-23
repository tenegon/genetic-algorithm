#ifndef MULTIPLEHEURISTICMUTATION_H
#define MULTIPLEHEURISTICMUTATION_H
#include "heuristicmutation.h"

class MultipleHeuristicMutation : public HeuristicMutation
{
public:
    MultipleHeuristicMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint, Valuer *valuer, NumericConstraint *attemptsConstraint);
    void mutation(const uint &gene, RealIndividual *mutant);
    void mutation(RealIndividual *mutant);
};

#endif // MULTIPLEHEURISTICMUTATION_H
