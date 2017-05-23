#ifndef UNARYHEURISTICMUTATION_H
#define UNARYHEURISTICMUTATION_H
#include "heuristicmutation.h"

class UnaryHeuristicMutation : public HeuristicMutation
{
public:
    UnaryHeuristicMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint, Valuer *valuer, NumericConstraint *attemptsConstraint);
    void mutation(const uint &gene, RealIndividual *mutant);
    void mutation(RealIndividual *mutant);
};

#endif // UNARYHEURISTICMUTATION_H
