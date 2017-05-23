#ifndef UNIFORMMUTATION_H
#define UNIFORMMUTATION_H
#include "realmutation.h"

class UniformMutation : public RealMutation
{
public:
    UniformMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint);
    void mutation(const uint &gene);
};

#endif // UNIFORMMUTATION_H
