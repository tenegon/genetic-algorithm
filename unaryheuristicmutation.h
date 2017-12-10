#ifndef UNARYHEURISTICMUTATION_H
#define UNARYHEURISTICMUTATION_H
#include "heuristicmutation.h"

class UnaryHeuristicMutation : public HeuristicMutation
{
public:
    UnaryHeuristicMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, Valuer *valuer, NumericConstraint<uint> *attemptsConstraint);
    ~UnaryHeuristicMutation();
    void mutation(const uint &gene, Individual *mutant);
    void mutation(Individual *mutant);
    void print(std::ostream& os) const;
};

#endif // UNARYHEURISTICMUTATION_H
