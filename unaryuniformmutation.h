#ifndef UNARYUNIFORMMUTATION_H
#define UNARYUNIFORMMUTATION_H
#include "uniformmutation.h"


class UnaryUniformMutation : public UniformMutation
{
public:
    UnaryUniformMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint);
    void mutation(const uint &gene, RealIndividual *mutant);
    void mutation(RealIndividual *mutant);
};

#endif // UNARYUNIFORMMUTATION_H
