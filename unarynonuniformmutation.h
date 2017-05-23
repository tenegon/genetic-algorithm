#ifndef UNARYNONUNIFORMMUTATION_H
#define UNARYNONUNIFORMMUTATION_H
#include "nonuniformmutation.h"

class UnaryNonUniformMutation : public NonUniformMutation
{
public:
    UnaryNonUniformMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint, NumericConstraint *iterationsConstraint, uint *iteration);
    void mutation(const uint &gene, RealIndividual *mutant);
    void mutation(RealIndividual *mutant);
};

#endif // UNARYNONUNIFORMMUTATION_H
