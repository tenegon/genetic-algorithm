#ifndef BOUNDARYMUTATION_H
#define BOUNDARYMUTATION_H
#include "realmutation.h"

class BoundaryMutation : public RealMutation
{
public:
    BoundaryMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint);
    void mutation(const uint &gene);
};

#endif // BOUNDARYMUTATION_H
