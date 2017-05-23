#ifndef MULTIPLEBOUNDARYMUTATION_H
#define MULTIPLEBOUNDARYMUTATION_H
#include "boundarymutation.h"

class MultipleBoundaryMutation : public BoundaryMutation
{
public:
    MultipleBoundaryMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint);
    void mutation(const uint &gene, RealIndividual *mutant);
    void mutation(RealIndividual *mutant);
};

#endif // MULTIPLEBOUNDARYMUTATION_H
