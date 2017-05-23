#ifndef NONUNIFORMMUTATION_H
#define NONUNIFORMMUTATION_H
#include "realmutation.h"

class NonUniformMutation : public RealMutation
{
protected:
    double b;
    NumericConstraint *iterationsConstraint;
    uint *iteration;
public:
    NonUniformMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint, NumericConstraint *iterationsConstraint, uint *iteration);
    void mutation(const uint &gene);
    double fg();
};

#endif // NONUNIFORMMUTATION_H
