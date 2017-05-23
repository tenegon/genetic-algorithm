#ifndef UNARYBOUNDARYMUTATION_H
#define UNARYBOUNDARYMUTATION_H
#include "boundarymutation.h"

class UnaryBoundaryMutation : public BoundaryMutation
{
public:
    UnaryBoundaryMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint);
    void mutation(const uint &gene, RealIndividual *mutant);
    void mutation(RealIndividual *mutant);
};

#endif // UNARYBOUNDARYMUTATION_H
