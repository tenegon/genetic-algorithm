#ifndef NONUNIFORMMUTATION_H
#define NONUNIFORMMUTATION_H
#include "realmutation.h"

class NonUniformMutation : public RealMutation
{
protected:
    NumericConstraint<uint> *iterationsConstraint;
    double b;
public:
    NonUniformMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, NumericConstraint<uint> *iterationsConstraint, double b = 6.0);
    ~NonUniformMutation();
    void mutation(const uint &gene);
    double fg();
};

#endif // NONUNIFORMMUTATION_H
